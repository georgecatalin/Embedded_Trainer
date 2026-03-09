/*
The publisher-subscriber pattern can also be implemented with array-based structures instead of linked lists.

The use of arrays is very common in embedded C because:
- avoid malloc()
- has predictable memory usage
- is easier to debug
- is often safer on smaller systems

*/

#include <stdio.h>

#define MAX_SUBSCRIBERS 8

/* Each subscribe must provide  a function of this signature */
typedef void (*SubscriberCallback) (int value, void *user_data);

/* Each array element is one possible subscriber described by this struct. */
typedef struct SubscriberSlot
{
    SubscriberCallback callback;
    void *user_data;
    int slot_in_use;
} SubscriberSlot_t;

/* The publisher owns a fixed array of subscriber slots. 
Thus, memory is allocated at compile time or on the stack, depending where the publisher leaves
*/
typedef struct Publisher
{
    SubscriberSlot_t slots[MAX_SUBSCRIBERS];
} Publisher_t;

/* Initialize publisher */
void publisher_initialize(Publisher_t *publisher)
{
    int i;

    for (i=0; i< MAX_SUBSCRIBERS; i++)
    {
        publisher->slots[i].callback = NULL;
        publisher->slots[i].user_data = NULL;
        publisher->slots[i].slot_in_use = 0;
    }
}

/* Subscribe the subscriber */
int publisher_subscribe(Publisher_t *publisher, SubscriberCallback cb, void *user_data)
{
    int i;
    for(i = 0;i<MAX_SUBSCRIBERS;i++)
    {
        if (!publisher->slots[i].slot_in_use)
        {
            publisher->slots[i].callback = cb;
            publisher->slots[i].user_data = user_data;
            publisher->slots[i].slot_in_use = 1;
            return 0;
        }
    }
   return -1; //no free slot is available
}

/* Notify the subscribers */
void publisher_notifies(Publisher_t *publisher, int value)
{
    for(int i = 0; i<MAX_SUBSCRIBERS; i++)
    {
        if(publisher->slots[i].slot_in_use && publisher->slots[i].callback)
        {
            publisher->slots[i].callback(value,publisher->slots[i].user_data);
        }
    }
}

/* Example callback functions */
void logger_log(int value, void *user_data)
{
    printf("[LOGGER] Logged value %d.\n", value);
}

void alarm_check(int value, void *user_data)
{
    int threshold_value =*(int *) user_data;
    if(value>threshold_value)
    {
        printf("[ALARM] Threshold value %d is less the current value %d.\n", threshold_value,value);
    }
}

void display_view(int value, void *user_data)
{
    const char *name= (const char *) user_data;
    printf("[%s] displays value %d.\n", name, value);
}

/* publisher clean up subcribers */
void publisher_cleanup(Publisher_t *publisher)
{
    int i;
    for(i=0;i<MAX_SUBSCRIBERS;i++)
    {
        publisher->slots[i].callback = NULL;
        publisher->slots[i].user_data = NULL;
        publisher->slots[i].slot_in_use = 0;
    }
}

/* The real usage example */
int main(void)
{
    Publisher_t sensor;
    int threshold_value = 18;

    /* initialize publisher */
    publisher_initialize(&sensor);

    /* subscribe to publisher */
    publisher_subscribe(&sensor,logger_log, NULL);
    publisher_subscribe(&sensor,alarm_check,&threshold_value);
    publisher_subscribe(&sensor,display_view,"SAMSUNG");

    /* Notify the subscribers */
    printf("Publisher notifies 10\n");
    publisher_notifies(&sensor, 10);

    printf("Publisher notifies 50\n");
    publisher_notifies(&sensor, 50);

    /* Clean up */
    printf("Publisher cleans up \n");
    publisher_cleanup(&sensor);

    return 0;
}