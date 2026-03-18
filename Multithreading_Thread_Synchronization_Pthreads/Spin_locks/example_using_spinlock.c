#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
pthread_spinlock_t my_spinlock;

void *worker(void *arg)
{
    int local_count = 0;

    for (int i = 0; i <= 10000; i++)
    {
        pthread_spin_lock(&my_spinlock);
        counter++;
        pthread_spin_unlock(&my_spinlock);
    }
    
    local_count++;

    printf("Shared counter is %d, whereas local counter is %d.\n", counter, local_count);

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread1, thread2;

    pthread_spin_init(&my_spinlock,PTHREAD_PROCESS_PRIVATE);

    pthread_create(&thread1,NULL,worker,NULL);
    pthread_create(&thread2,NULL,worker,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    pthread_spin_destroy(&my_spinlock);

    printf("Counter: %d.\n", counter);

    return 0;
}

/*
what happens here
when thread1 gets the lock, thread2 does not go to sleep.
thread2 still tries to get the lock, until it gets it. and eventually it gets the lock

when the critical section is small, then keeping thread2 awake costs less in terms of CPU time
than putting to sleep and waking up the thread2.

*/