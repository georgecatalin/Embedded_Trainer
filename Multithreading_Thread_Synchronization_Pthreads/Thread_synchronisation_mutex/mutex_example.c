#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>

int my_array[] = {1,2,3,4,5};
pthread_mutex_t this_mutex;

void print_array()
{
    int len_array = sizeof(my_array)/sizeof(my_array[0]);

    int i;

    for (i = 0; i < len_array -1; i++)
    {
        printf("%d ",my_array[i]);
    }
    
    printf("%d \n", my_array[i]);
}

/* a thread callback function must have the following prototype 
*    void * (*thread_function) (void *)
* */

static void *thread_function_callback_sum(void * arg)
{
    int i = 0;
    int sum = 0;

    int array_length = sizeof(my_array)/sizeof(my_array[0]);

    do
    {
        pthread_mutex_lock(&this_mutex);
        while (i<array_length)
        {
            sum +=my_array[i];
            i++;
        }
        assert(sum == 15);
        pthread_mutex_unlock(&this_mutex);

        print_array();
        printf("Sum of elements is %d.\n",sum);

    } while (1);
}

static void *thread_function_callback_swap(void * arg)
{
    int array_length = sizeof(my_array)/sizeof(my_array[0]);

    do
    {
        pthread_mutex_lock(&this_mutex);
        int temp = my_array[0];
        my_array[0]=my_array[array_length-1];
        my_array[array_length-1]= temp;
        print_array();
        pthread_mutex_unlock(&this_mutex);
    } while (1);
}

void sum_thread_create()
{
    pthread_t thread1;

    int return_code = pthread_create(&thread1,NULL,thread_function_callback_sum,NULL);

    if (return_code != 0)
    {
        fprintf(stderr,"Error on creating sum thread %s \n", strerror(errno));
        exit(0);
    }
}

void swap_thread_create()
{
    pthread_t thread2;

    int return_code = pthread_create(&thread2,NULL,thread_function_callback_swap, NULL);

    if (return_code != 0)
    {
        fprintf(stderr,"Error on creating swap thread %s \n", strerror(errno));
        exit(0);
    }
}

int main(void)
{
    pthread_mutex_init(&this_mutex,0);

    sum_thread_create();
    swap_thread_create();

    pthread_mutex_destroy(&this_mutex);

    //allow the main thread to exit, while the other threads keep on running
    pthread_exit(0);

    return 0;
}