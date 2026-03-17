#include "thread_barriers.h"

static thread_barrier_t thread_barrier;
static pthread_t pthreads[3];

void *thread_callback(void *arg)
{
    thread_barrier_wait(&thread_barrier);
    printf("1st barrier passed through by thread %s.\n", (char *) arg); //it gets printed only when all 3 have got to the barrier

    thread_barrier_wait(&thread_barrier);
    printf("2nd barrier passed through by thread %s. \n", (char *) arg);

    thread_barrier_wait(&thread_barrier);
    printf("3rd barrier passed through by thread %s. \n", (char *) arg);
}

int main(int argc, char **argv)
{
    thread_barrier_init(&thread_barrier,3);

    //create the threads, one by one
    static const char *thread1_name = "thread1";
    pthread_create(&pthreads[0],NULL,thread_callback,(void *) thread1_name);

    static const char *thread2_name = "thread2";
    pthread_create(&pthreads[1],NULL,thread_callback,(void *) thread2_name);

    static const char *thread3_name = "thread3";
    pthread_create(&pthreads[2],NULL,thread_callback,(void *) thread3_name);

    pthread_join(pthreads[1],NULL);
    pthread_join(pthreads[2],NULL);
    pthread_join(pthreads[3],NULL);

    thread_barrier_print(&thread_barrier);

    return 0;
}