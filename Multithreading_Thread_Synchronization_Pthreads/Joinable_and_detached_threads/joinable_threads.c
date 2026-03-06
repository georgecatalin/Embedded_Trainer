#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_t thread1;
pthread_t thread2;

void *thread_fn_callback(void *arg)
{
   int number_passed = *(int *) arg;

   //free memory in the caller
   free(arg);
   arg = NULL;



   int *result = (int *) calloc(1, sizeof(int));

   *result = number_passed * number_passed;

   int rc = 0;

   while(rc < number_passed)
   {
    printf("the thread is doing its work...\n");
    sleep(1);
    rc ++;
   }

   return (void *) result;
}


void thread_create(pthread_t *thread_handle, int number_to_use)
{
    // set the attributes of the thread to be joinable
    pthread_attr_t the_attributes;
    pthread_attr_init(&the_attributes); //for correctness, although it might lack
    pthread_attr_setdetachstate(&the_attributes, PTHREAD_CREATE_JOINABLE);

    // set the value to be passed to the thread on the heap or static
    int *the_passing_var = (int *)calloc(1, sizeof(int));
    *the_passing_var = number_to_use; //store the value on the heap to be able to transmit to the thread

    //create the new thread
    pthread_create(thread_handle, &the_attributes, thread_fn_callback, (void *)the_passing_var);

    pthread_attr_destroy(&the_attributes); //for correctness, although it might lack
}

int main(void)
{
    thread_create(&thread1, 10);
    thread_create(&thread2, 3);

    printf("Main thread is blocked waiting for the joining of thread 1.\n");

    void *result_from_thread1;
    pthread_join(thread1,&result_from_thread1);

    if(result_from_thread1)
    {
        printf("thread 1 returned the value %d\n", *(int *)result_from_thread1);

        //free memory in the caller
        free(result_from_thread1);
        result_from_thread1 = NULL;
    }

    printf("Main thread is blocked waiting for the joining of thread 2.\n");

    void *result_from_thread2;
    pthread_join(thread2,&result_from_thread2);

    if(result_from_thread2)
    {
        printf("thread 2 returned the value %d\n", *(int *)result_from_thread2);

        free(result_from_thread2);
        result_from_thread2 = NULL;
    }

    return 0;
}