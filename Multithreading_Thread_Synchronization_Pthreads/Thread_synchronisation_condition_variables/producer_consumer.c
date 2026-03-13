#if 0

Problem Statement :
====================
Write a program which launches 4 threads - 2 consumer threads and 2 producer threads. Threads
are created in JOINABLE Mode.
All 4 threads act on a shared resource - A Queue of integers. Producer threads produce
a random integer and add it to Queue, Consumer threads remove an integer from the Queue.
Maximum size of the Queue is 5.

Following are the constraints applied :

1. When producer threads produce an element and add it to the Queue, it does not release the Queue
untill the Queue is full i.e producer thread release the Queue only when it is full

2. When consumer threads consume an element from the Queue, it consumes the entire Queue and
do not release it until the Queue is empty.

3. Consumer Signals the Producers when Queue is Exhausted, Producers Signals the Consumers when Queue	
becomes full

Guidelines :
Use as many printfs as possible, so you can debug the program easily

#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include "queue.h"

static int return_new_int()
{
    static int a = 0;
    a++;
    return a;
}

static char *producer1 = "TP1";
static char *producer2 = "TP2";
static char *consumer1 = "TC1";
static char *consumer2 = "TC2";

struct Queue_t *my_queue;

static void *producer_fn(void *arg)
{
    const char *thread_name = (char *)arg;

    printf("Thread [%s] is waiting to lock the mutex.{function: %s, line number:%d, file name:%s}\n", thread_name, __func__, __LINE__, __FILE__);
    pthread_mutex_lock(&my_queue->q_mutex);
    printf("Thread [%s] acquired the mutex.{function: %s, line number:%d, file name:%s}\n", thread_name, __func__, __LINE__, __FILE__);

    // Predicate check
    while (is_queue_full(my_queue))
    {
        printf("Thread [%s] blocks itself, as the queue is already full {function:%s, line number:%d, file name:%s} \n", thread_name, __func__, __LINE__, __FILE__);
        pthread_cond_wait(&my_queue->q_cv, &my_queue->q_mutex);
        printf("Thread [%s] wakes up, checks the condition again . {function:%s, line number:%d, file name:%s} \n", thread_name, __func__, __LINE__, __FILE__);
    }

    //start of critical section for producer -> producer starts producing only when the queue is empty
    assert(is_queue_empty(my_queue));

    int i;
    //new predicate
    while(!is_queue_full(my_queue))
    {
        i = return_new_int();
        printf("Thread [%s] produces a new integer %d {function:%s, line number:%d, file name:%s} \n", thread_name, i, __func__,__LINE__,__FILE__);
        enqueue(my_queue, (void *) i);
        printf("Thread [%s] pushed the integer %d to the queue. the size is %d. {function:%s, line number:%d, file name:%s} \n ",
                                thread_name, i, my_queue->count,__func__,__LINE__,__FILE__);
    }

    printf("Thread %s Filled up the Queue, signalling and releasing lock\n", thread_name);
	pthread_cond_broadcast(&my_queue->q_cv); /* S8 */

	/* End of CS of producer */
	pthread_mutex_unlock(&my_queue->q_mutex); /* S9 */
	printf("Thread %s finished, and exit\n", thread_name);

    return NULL;
}

static void *consumer_fn(void *arg)
{
    const char *thread_name = (char *)arg;

    printf("Thread [%s] is waiting to lock the mutex.{function: %s, line number:%d, file name:%s}\n", thread_name, __func__, __LINE__, __FILE__);
    pthread_mutex_lock(&my_queue->q_mutex);
    printf("Thread [%s] acquired the mutex.{function: %s, line number:%d, file name:%s}\n", thread_name, __func__, __LINE__, __FILE__);

    // Predicate check
    while (is_queue_empty(my_queue))
    {
        printf("Thread [%s] blocks itself, as the queue is already empty {function:%s, line number:%d, file name:%s} \n", thread_name, __func__, __LINE__, __FILE__);
        pthread_cond_wait(&my_queue->q_cv, &my_queue->q_mutex);
        printf("Thread [%s] wakes up, checks the condition again . {function:%s, line number:%d, file name:%s} \n", thread_name, __func__, __LINE__, __FILE__);
    }

    //start of critical section for consumer. consumer starts to consume only when the queue is full
    assert(is_queue_full(my_queue));

    int i;
    while (!is_queue_empty(my_queue))
    {
        i = (int) deque(my_queue);
        printf("Thread [%s] consumes an integer [%d] from the queue and the new size of the queue is %d {function:%s, line number:%d, file name:%s} \n",
               thread_name, i, my_queue->count, __func__,__LINE__,__FILE__);
    }
    
    printf("Thread [%s] drained the entire queue and sends a signal to the other threads in blocking state \n", thread_name);
    pthread_cond_broadcast(&my_queue->q_cv);

    printf("The thread [%s] is releasing the lock on the queue and it can be used elsewhere. \n",thread_name);
    pthread_mutex_unlock(&my_queue->q_mutex);
    printf("Thread %s finished, and exit\n", thread_name);

    return NULL;
}

int main(int argc, char **argv)
{
    my_queue = initQ();

    pthread_t producer_thread1, producer_thread2;
    pthread_t consumer_thread1, consumer_thread2;

    // create and set the attribute for joinable threads
    pthread_attr_t the_attribute;
    pthread_attr_init(&the_attribute);
    pthread_attr_setdetachstate(&the_attribute, PTHREAD_CREATE_JOINABLE);

    // create the threads
    pthread_create(&producer_thread1, &the_attribute, producer_fn, (void *)producer1);
    pthread_create(&producer_thread2, &the_attribute, producer_fn, (void *)producer2);

    pthread_create(&consumer_thread1, &the_attribute, consumer_fn, (void *)consumer1);
    pthread_create(&consumer_thread2, &the_attribute, consumer_fn, (void *)consumer2);

    // join the threads into the main()
    pthread_join(producer_thread1, 0);
    pthread_join(producer_thread2, 0);
    pthread_join(consumer_thread1, 0);
    pthread_join(consumer_thread2, 0);

    printf("Program has finished. \n");

    //Clean up things
    pthread_mutex_destroy(&my_queue->q_mutex);
    pthread_cond_destroy(&my_queue->q_cv);
    free(my_queue);
    my_queue = NULL;
 
    pthread_exit(0);

    return 0;
}