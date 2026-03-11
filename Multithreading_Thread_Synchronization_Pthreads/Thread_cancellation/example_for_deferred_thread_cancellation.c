#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

#define NUMBER_OF_SLAVES 7

pthread_t slaves[NUMBER_OF_SLAVES];

// write the functions used to gracefully thread cancel
void memory_cleaning_before_thread_cancellation(void *arg)
{
    printf("%s was invoked in Line number: %d and File:%s\n", __func__, __LINE__, __FILE__);
    free(arg);
}

void file_pointer_cleaning_before_cancellation(void *arg)
{
    printf("%s was invoked in line number:%d of file:%s\n", __func__, __LINE__, __FILE__);
    FILE *ptr = (FILE *)arg;
    fclose(arg);
}

void *write_into_file(void *arg)
{
    char filename[64];
    char string_to_write[64];
    int len = 0;
    int count = 0;

    /* set the thread as cancellable */
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);

    /* set the type of the thread cancellation to asynchronous */
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0); // By using deferred cancellation we control the cancellation point of the thread

    int *thread_id = (int *)arg;

    sprintf(filename, "thread_%d.txt", *thread_id);

    // enter the POSIX function to gracefully allow the cancellation of the thread
    pthread_cleanup_push(memory_cleaning_before_thread_cancellation, arg);

    FILE *ptr_file = fopen(filename, "w");

    if (!ptr_file)
    {
        fprintf(stderr, "Error [%s] on opening file %s.\n", strerror(errno), filename);
        // In older versions of C, if the compiler encounters a function it doesn't recognize, it simply
        // guesses that the function returns a standard integer (int).
        //return NULL; //avoid using return, cause it will not allow cleanup_pop execution
        pthread_exit(0);
    }

    // enter the POSIX function to gracefully allow the cancellation of the thread
    pthread_cleanup_push(file_pointer_cleaning_before_cancellation, ptr_file);

    while (1)
    {
        sprintf(string_to_write, "%d: thread id %d writes \n", count++, *thread_id);
        fwrite(string_to_write, sizeof(char), len, ptr_file);
        fflush(ptr_file);
        sleep(1);

        pthread_testcancel(); //this is the POSIX API the sets the cancellation point, in case that the thread is cancelled. Solves the invariants issue
    }

    // pop the POSIX clean-up functions out of the stack in case that threads were not cancelled
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
}

int main(void)
{
    int i;
    int *thread_id = NULL;

    for (i = 0; i < NUMBER_OF_SLAVES; i++)
    {
        thread_id = (int *)calloc(1, sizeof(int));
        *thread_id = i;
        pthread_create(&slaves[i], NULL, write_into_file, thread_id);
    }

    /* implement menu */
    int choice = 0;
    int thread_number = 0;

    while (1)
    {
        printf("1. Cancel the thread.\n");
        scanf("%d", &choice);
        printf("Enter the thread number [0..%d]: ", NUMBER_OF_SLAVES - 1);
        scanf("%d", &thread_number);

        if ((thread_number < 0) || (thread_number > NUMBER_OF_SLAVES - 1))
        {
            printf("Invalid choice, pal!!!");
            return -1;
        }

        switch (choice)
        {
        case 1:
            pthread_cancel(slaves[thread_number]);
            break;

        default:
            break;
        }
    }

    return 0;
}