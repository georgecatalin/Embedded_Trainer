/*
Let threads be A, B, C.

A enters: not last → curr_wait_count=1 → waits on cv
B enters: not last → curr_wait_count=2 → waits on cv
C enters: sees 2 + 1 == 3 → is last
sets is_barrier_available=false
signals cv waking either A or B
returns (C does not wait)
Suppose A wakes:

A decrements curr_wait_count to 1
since not zero, A signals cv waking B, unlocks, returns
B wakes:

B decrements curr_wait_count to 0
sets is_barrier_available=true
broadcasts busy_cv (allow next round entrants)
unlocks, returns
Now barrier is ready for next use.
*/





#include "thread_barriers.h"

void thread_barrier_print(thread_barrier_t *barrier)
{
    printf("Thread barrier threshold count = %u\n", barrier->threshold_count);
    printf("Thread barrier threads blocked= %u\n", barrier->no_threads_currently_blocked);
    printf("Thread barrier is_available = %s\n", barrier->is_barrier_available ? "true" : "false");
}

void thread_barrier_init(thread_barrier_t *barrier, uint32_t threshold_count)
{
    barrier->threshold_count = threshold_count;
    barrier->no_threads_currently_blocked = 0;
    barrier->is_barrier_available = true;
    pthread_cond_init(&barrier->condition_variable,NULL);
    pthread_mutex_init(&barrier->mutex, NULL);
    pthread_cond_init(&barrier->busy_condition_variable,NULL);
}


/// @brief Threads call thread_barrier_wait(barrier). If you are not the last thread to arrive as per the threshold for the round, then sleep on the condition variable
/// If you are the last thread for the round as per the threshold , you start the release chain by waking up another waiter thread
/// Then each waiting thread wakes the next one until the last waiting thread resets the barrier and lets the new round begin
/// @param barrier 
void thread_barrier_wait(thread_barrier_t *barrier)
{
    pthread_mutex_lock(&barrier->mutex);
   

    //If barrier is “busy resetting”, wait outside this round
    if(barrier->is_barrier_available == false)
    {
        pthread_cond_wait(&barrier->busy_condition_variable,&barrier->mutex);

        /*
        pthread_cond_wait() atomically:
                releases the mutex
                sleeps
                e-acquires the mutex before returning

        This while loop is correct style: condition variables can wake spuriously, so you always re-check the condition.

        Meaning of this gate:

        If the barrier is currently releasing threads from the previous round (is_ready_again == false), 
        new threads must not enter and mix with the previous round.
        
        */
    }

    // Check if I am the last arriving thread
    if(barrier->no_threads_currently_blocked + 1 == barrier->threshold_count)  // I’m the last thread to arrive for this round.
    {
        //Close the gate so new threads (next round) can’t start entering while we’re releasing this round.
        barrier->is_barrier_available = false;
        //Wake one thread waiting on the condition variable (one of the earlier arrivals).
        pthread_cond_signal(&barrier->condition_variable);
        // The last thread does not wait at the barrier, it starts the release only
        pthread_mutex_unlock(&barrier->mutex);
        return;
    }

    //ok I am not the last thread to arrive at the barrier at this round
    barrier->no_threads_currently_blocked++; //because I’m joining the set of waiting threads.
    pthread_cond_wait(&barrier->condition_variable,&barrier->mutex); //sleep on the condition variable until another thread wakes me up(the last thread initiates the release process)
    barrier->no_threads_currently_blocked--; //when i wake up, i am no longer blocked

    //decide if i am the last remaining thread waiting
    if(barrier->no_threads_currently_blocked == 0)
    {
        //i am the last waiting thread to be released
        barrier->is_barrier_available =  true; //new threads can enter ; round is done, and we can reset the barrier for reuse.
        pthread_cond_broadcast(&barrier->busy_condition_variable); //announce all threads from the new round the barrier is up
    }
    else
    {
        //i am not the last waiting thread to be released. pass the signal to wake up the next waiting thread
        pthread_cond_signal(&barrier->condition_variable);
    }

    pthread_mutex_unlock(&barrier->mutex);
    return;
}


void thread_barrier_destroy(thread_barrier_t *barrier)
{
   //implement 
   pthread_cond_destroy(&barrier->condition_variable);
   pthread_mutex_destroy(&barrier->mutex);
   pthread_cond_destroy(&barrier->busy_condition_variable);
}