#ifndef _CUSTOM_SEMAPHORE_
#define _CUSTOM_SEMAPHORE_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>



struct custom_semaphore
{
    int permit_counter;
    pthread_cond_t condition_variable;
    pthread_mutex_t mutex;
};

typedef struct custom_semaphore custom_semaphore_t;

custom_semaphore_t *custom_sema_get_new_semaphore();

void custom_sema_init(custom_semaphore_t *custom_semaphore, int permit_counter);
void custom_sema_wait(custom_semaphore_t *custom_semaphore);
void custom_sema_post(custom_semaphore_t *custom_semaphore);
void custom_sema_destroy(custom_semaphore_t *custom_semaphore);

int getvalue(custom_semaphore_t *custom_semaphore);

#define P(custom_semaphore) (custom_sema_wait(custom_semaphore))
#define V(custom_semaphore) (custom_sema_post(custom_semaphore))

#define UP(custom_semaphore) (custom_sema_wait(custom_semaphore))
#define DOWN(custom_semaphore) (custom_sema_post(custom_semaphore))

#endif