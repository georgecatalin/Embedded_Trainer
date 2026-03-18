#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

/* resolve strict alternation problem of running two threads A and B without intervention of the scheduler */

sem_t semaphore_a;
sem_t semaphore_b;

static void *threadA_function(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        sem_wait(&semaphore_a);
        printf("Executing thread A. \n");
        sem_post(&semaphore_b);

    }

    return NULL;
}

static void *threadB_function(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&semaphore_b);
        printf("Executing thread B. \n");
        sem_post(&semaphore_a);
    }
    

    return NULL;
}


int main(void)
{
    sem_init(&semaphore_a,0,1);
    sem_init(&semaphore_b,0,0);

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, threadA_function, NULL);
    pthread_create(&thread2, NULL, threadB_function, NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    sem_destroy(&semaphore_a);
    sem_destroy(&semaphore_b);

    return 0;
}