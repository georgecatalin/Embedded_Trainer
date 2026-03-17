#include "dining_philosophers.h"

#define NUMBER_PHILOSPHERS 5

static philosopher_t philosophers[NUMBER_PHILOSPHERS];
static spoon_t spoons[NUMBER_PHILOSPHERS];

static spoon_t *philosopher_take_spoon_at_right(philosopher_t *philosopher)
{
    int philosopher_id = philosopher->philosopher_id;

    if (philosopher_id == 0)
        return &spoons[NUMBER_PHILOSPHERS - 1];

    return &spoons[philosopher_id - 1];
}

static spoon_t *philosopher_take_spoon_at_left(philosopher_t *philosopher)
{
    return &spoons[philosopher->philosopher_id];
}

static void philosopher_eats(philosopher_t *philosopher)
{
    spoon_t *left_spoon = philosopher_take_spoon_at_left(philosopher);
    spoon_t *right_spoon = philosopher_take_spoon_at_right(philosopher);

    assert(left_spoon->philosopher == philosopher);
    assert(right_spoon->philosopher == philosopher);

    assert(left_spoon->is_spoon_used == true);
    assert(right_spoon->is_spoon_used == true);

    philosopher->counter_eat++;

    printf("philosopher %d is eating the cake with the spoons [%d,%d] and has eaten that many times ->%d\n",
           philosopher->philosopher_id, left_spoon->spoon_id, right_spoon->spoon_id, philosopher->counter_eat);

    sleep(1);
}

static void philosopher_release_access_to_both_spoons(philosopher_t *philosopher)
{
    spoon_t *left_spoon = philosopher_take_spoon_at_left(philosopher);
    spoon_t *right_spoon = philosopher_take_spoon_at_right(philosopher);

    //at this point the philosopher has access to both spoons, and this has to be validated
    assert(left_spoon->philosopher == philosopher);
    assert(left_spoon->is_spoon_used == true);

    assert(right_spoon->philosopher == philosopher);
    assert(right_spoon->is_spoon_used == true);

    pthread_mutex_lock(&left_spoon->mutex);
    pthread_mutex_lock(&right_spoon->mutex);

    left_spoon->philosopher = NULL;
    left_spoon->is_spoon_used = false;

    printf("The philosopher %d released the left spoon %d. \n", philosopher->philosopher_id, left_spoon->spoon_id );

    pthread_cond_signal(&left_spoon->condition_variable);
    printf("The philosopher %d signalled the release of the spoon %d.\n", philosopher->philosopher_id, left_spoon->spoon_id);

    pthread_mutex_unlock(&left_spoon->mutex);


    right_spoon->philosopher = NULL;
    right_spoon->is_spoon_used = false;

    printf("The philosopher %d released the right spoon %d.\n", philosopher->philosopher_id, right_spoon->spoon_id);
    pthread_cond_signal(&right_spoon->condition_variable);
    printf("The philosopher %d signalled the release of the spoon %d.\n", philosopher->philosopher_id, left_spoon->spoon_id);
    pthread_mutex_unlock(&right_spoon->mutex);

}

static bool philosopher_gets_access_to_both_spoons(philosopher_t *philosopher)
{
    spoon_t *left_spoon = philosopher_take_spoon_at_left(philosopher);
    spoon_t *right_spoon = philosopher_take_spoon_at_right(philosopher);

    printf("Philosopher %d is waiting for lock on the left spoon %d \n", philosopher->philosopher_id, left_spoon->spoon_id);
    pthread_mutex_lock(&left_spoon->mutex);
    printf("Philosopher %d is inspecting the state of the left spoon %d \n", philosopher->philosopher_id, left_spoon->spoon_id);

    while (left_spoon->is_spoon_used == true && left_spoon->philosopher != philosopher)
    {
        printf("philosopher %d blocks because the left spoon %d is not available \n", philosopher->philosopher_id, left_spoon->spoon_id);
        pthread_cond_wait(&left_spoon->condition_variable, &left_spoon->mutex);

        printf("philosopher %d receives signal that the left spoon %d is again available. \n", philosopher->philosopher_id, left_spoon->spoon_id);

    }
    
    //case 2 left spoon is available and search for the right spoon
    printf("philosopher %d finds the left spoon %d available and grabs it.\n", philosopher->philosopher_id, left_spoon->spoon_id);
    left_spoon->is_spoon_used = true;
    left_spoon->philosopher = philosopher;
    printf("philosopher %d grabbed successfully the left spoon. %d .\n", philosopher->philosopher_id, left_spoon->spoon_id);
    pthread_mutex_unlock(&left_spoon->mutex);


    printf("philosopher %d attempts to get access to the right spoon %d.\n", philosopher->philosopher_id, right_spoon->spoon_id);
    pthread_mutex_lock(&right_spoon->mutex);
    printf("at all times, before inspecting a resource, block it to make sure no one, alter its status \n");

    if(right_spoon->is_spoon_used == false)
    {
        right_spoon->is_spoon_used = true;
        right_spoon->philosopher = philosopher; //grab the spoon
        pthread_mutex_unlock(&right_spoon->mutex);
        return true;
    }
    else
    {
        if(right_spoon->philosopher != philosopher)
        {
            printf("philosopher %d notices the right spoon %d is owned by the other philosopher %d and therefore he must release the left spoon.\n",
            philosopher->philosopher_id, left_spoon->spoon_id, left_spoon->philosopher->philosopher_id);

            pthread_mutex_lock(&left_spoon->mutex);
            assert(left_spoon->is_spoon_used == true);
            assert(left_spoon->philosopher == philosopher);

            left_spoon->is_spoon_used = false;
            left_spoon->philosopher = NULL;

            printf("philosopher %d released the left spoon %d.\n", philosopher->philosopher_id, left_spoon->spoon_id);

            pthread_mutex_unlock(&left_spoon->mutex);
            pthread_mutex_unlock(&right_spoon->mutex);
            return false;
        }
        else
        {
            printf("philosopher %d already has the right spoon %d. \n", philosopher->philosopher_id, right_spoon->spoon_id);
            pthread_mutex_unlock(&right_spoon->mutex);
            return true;
        }

        assert(0); //dead code - never gets here
        return false;
    }






}

void *philosopher_callback_fn(void *arg)
{
    philosopher_t *philosopher = (philosopher_t *) arg;

    while(1)
    {
        if(philosopher_gets_access_to_both_spoons(philosopher))
        {
            philosopher_eats(philosopher);
            philosopher_release_access_to_both_spoons(philosopher);
            sleep(1);
        }
    }


}

int main(int argc, char **argv)
{
    int i;
    pthread_attr_t attribute;

    (void)argc;
    (void)argv;

    // initialize all spoons
    for (i = 0; i < NUMBER_PHILOSPHERS; i++)
    {
        spoons[i].spoon_id = i;
        spoons[i].is_spoon_used = false;
        spoons[i].philosopher = NULL;
        pthread_mutex_init(&spoons[i].mutex, NULL);
        pthread_cond_init(&spoons[i].condition_variable, NULL);
    }

    // set the attributes for the philosophers threads
    pthread_attr_init(&attribute);
    pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_DETACHED);

    // initialize all philosophers threads
    for (i = 0; i < NUMBER_PHILOSPHERS; i++)
    {
        philosophers[i].philosopher_id = i;
        philosophers[i].counter_eat = 0;
        pthread_create(&philosophers[i].pthread_handle, &attribute, philosopher_callback_fn, &philosophers[i]);
    }

    pthread_exit(0);
    return 0;
}