#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define NUMBER_ALLOWED_THREADS 2

pthread_t threads[5];
sem_t my_semaphore;

static void *thread_callback_function(void *arg)
{
   const char *thread_name = (char *) arg;

   printf("Thread '%s' is wishing to enter the critical section.\n", thread_name);

   sem_wait(&my_semaphore);

   printf("Thread '%s' enter the critical section. \n ", thread_name);
   /* begin of critical section */
   for (size_t i = 0; i < 5; i++)
   {
    printf("Thread '%s' is executing code in the critical section.\n");
    sleep(1);
   }

   printf("Thread '%s' is about to exit the critical section. \n", thread_name);
   /* end of critical section */
   printf("Thread '%s' exited the critical section. \n", thread_name);

   sem_post(&my_semaphore);
}

static void thread_create(pthread_t *thread_handle, void *arg)
{
    int return_code = pthread_create(thread_handle,NULL,thread_callback_function,arg);

    if (return_code != 0)
    {
        fprintf(stderr,"Error when creating the new thread with the message %s.\n", strerror(errno));
        exit(0);
    }
    
}

int main(void)
{
    sem_init(&my_semaphore,0,NUMBER_ALLOWED_THREADS);

    thread_create(&threads[0],"thread1");
    thread_create(&threads[1],"thread2");
    thread_create(&threads[2],"thread3");
    thread_create(&threads[3],"thread4");
    thread_create(&threads[4],"thread5");

    for (size_t i = 0; i < 5; i++)
    {
        pthread_join(threads[i],NULL);
    }
    
    sem_destroy(&my_semaphore);
    return 0;
}