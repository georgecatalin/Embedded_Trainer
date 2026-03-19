#include "custom_semaphore.h"

custom_semaphore_t *custom_sema_get_new_semaphore()
{
    custom_semaphore_t *new_semaphore = (custom_semaphore_t *) calloc(1,sizeof(custom_semaphore_t));

    if(!new_semaphore)
    {
        perror("Error when creating new semaphore object");
        return NULL;
    }

    return new_semaphore;
}

void custom_sema_init(custom_semaphore_t *custom_semaphore, int permit_counter)
{
    custom_semaphore->permit_counter = permit_counter;
    pthread_cond_init(&custom_semaphore->condition_variable, NULL);
    pthread_mutex_init(&custom_semaphore->mutex,NULL);
}



void custom_sema_wait(custom_semaphore_t *custom_semaphore)
{
    pthread_mutex_lock(&custom_semaphore->mutex);
    custom_semaphore->permit_counter--;

    if (custom_semaphore->permit_counter < 0)
    {
        pthread_cond_wait(&custom_semaphore->condition_variable, &custom_semaphore->mutex);
    }
    

    pthread_mutex_unlock(&custom_semaphore->mutex);
}


void custom_sema_post(custom_semaphore_t *custom_semaphore)
{
    bool are_there_other_threads_waiting;
    pthread_mutex_lock(&custom_semaphore->mutex);

    are_there_other_threads_waiting = custom_semaphore->permit_counter < 0 ? true : false;
    custom_semaphore->permit_counter++;

    if(are_there_other_threads_waiting)
        pthread_cond_signal(&custom_semaphore->condition_variable);

    pthread_mutex_unlock(&custom_semaphore->mutex);
}

void custom_sema_destroy(custom_semaphore_t *custom_semaphore)
{
    custom_semaphore->permit_counter = 0;
    pthread_mutex_unlock(&custom_semaphore->mutex);
    pthread_cond_destroy(&custom_semaphore->condition_variable);
    pthread_mutex_destroy(&custom_semaphore->mutex);

    free(custom_semaphore);
    custom_semaphore = NULL;
}

int getvalue(custom_semaphore_t *custom_semaphore)
{
    return custom_semaphore->permit_counter;
}