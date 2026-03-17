#ifndef _DINING_PHI_
#define _DINING_PHI_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>

struct philosopher
{
    int philosopher_id;
    pthread_t pthread_handle;
    int counter_eat;
};

typedef struct philosopher philosopher_t;


struct spoon
{
    int spoon_id;
    bool is_spoon_used;
    philosopher_t *philosopher;

    pthread_mutex_t mutex;
    pthread_cond_t  condition_variable;
};

typedef struct spoon spoon_t;


static spoon_t *philosopher_take_spoon_at_right(philosopher_t *philosopher);
static spoon_t *philosopher_take_spoon_at_left(philosopher_t *philosopher);
static void philosopher_eats(philosopher_t *philosopher);

static void philosopher_release_access_to_both_spoons(philosopher_t *philosopher);
static bool philosopher_gets_access_to_both_spoons(philosopher_t *philosopher);

#endif