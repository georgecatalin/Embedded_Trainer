#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void * thread_function_callback(void *arg)
{
    char *local_var = (char *) arg;

    while(1)
    {
        printf("the input string is %s.\n", local_var);
        sleep(2);
    }

}


static void thread_create(void)
{
    pthread_t thread1;

    //variable to be carried in the new thread. should either be static or on heap, otherwise it is on stack and will turn to segfault on runtime
    static char *thread_word ="Hello from thread1";

    int returned_code = pthread_create(&thread1,NULL,thread_function_callback, (void *) thread_word);

    if(returned_code != 0)
    {
        perror("Error creating new thread");
        exit(0);
    }
}


int main(void)
{
    thread_create();
    printf("Hello from main thread {Line number:%d, File name:%s}\n",__LINE__,__FILE__);
    pause();
    return 0;
}