#ifndef __THREAD_BARRIER_
#define __THREAD_BARRIER_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct thread_barrier
{
    /* how many threads must arrive */
    uint32_t threshold_count;
    /* how many threads are currently waiting inside the barrier */
    uint32_t no_threads_currently_blocked;
    /* condition variable used to release the fields through the barrier, controls releasing threads that are part of the current barrier round */
    pthread_cond_t condition_variable;
    /* protect the barrier fields */
    pthread_mutex_t mutex;

    /*
    boolean flag: 
    true: the barrier is ready to accept a new round
    false: the barrier is in the middle of releasing the threads/resetting and it does not allow new arrivals 
    */
    bool is_barrier_available;

    /* condition variable used to block the threads arriving while the barrier is resetting */
    pthread_cond_t busy_condition_variable;
} thread_barrier_t;

void thread_barrier_init(thread_barrier_t *barrier, uint32_t threshold_count);
void thread_barrier_wait(thread_barrier_t *barrier);
void thread_barrier_destroy(thread_barrier_t *barrier);
void thread_barrier_print(thread_barrier_t *barrier);


#endif