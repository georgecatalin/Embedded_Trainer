#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t my_lock;

void *worker(void *arg)
{
    int local_count = 0;

    for (int i = 0; i <= 10000; i++)
    {
        pthread_mutex_lock(&my_lock);
        counter++;
        pthread_mutex_unlock(&my_lock);

        local_count++;
    }

    printf("the shared counter is now -> %d, the local counter is -> %d. \n", counter, local_count);
    sleep(1);

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread1, thread2;

    pthread_mutex_init(&my_lock, NULL);

    pthread_create(&thread1,NULL,worker,NULL);
    pthread_create(&thread2,NULL,worker,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    pthread_mutex_destroy(&my_lock);

    printf("the counter is %d. \n", counter);

    return 0;
}

/*
what happens here:
if the lock is busy, then the thread goes to sleep
OS wakes it up later
mutex is good for longer waits
*/