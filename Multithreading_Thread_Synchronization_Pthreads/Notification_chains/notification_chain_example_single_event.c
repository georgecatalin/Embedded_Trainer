/*
Instead of passing a simple int, the publisher can pass a collection of elements in a struct  object.

For instace, we can publish a whole event object:
- temperature
- sensor ID;
- timestamp
*/

#include <stdio.h>

#define MAX_SUBSCRIBERS 8

typedef struct SensorEvent
{
     int temperature;
     int sensor_id;
     unsigned long timestamp;
}SensorEvent_t;

typedef void (*SubscriberCallback) (const SensorEvent_t *event, void *user_data);

typedef struct SubscriberSlot
{
    SubscriberCallback cb;
    void *user_data;
    int slot_in_use;
} SubscriberSlot_t;

typedef struct Publisher
{
    SubscriberSlot_t slots[MAX_SUBSCRIBERS];
} Publisher_t;


void publisher_initialize(Publisher_t *publisher)
{
    if(!publisher)
        return;

    for(int i=0;i<MAX_SUBSCRIBERS;i++)
    {
        publisher->slots[i].cb = NULL;
        publisher->slots[i].user_data = NULL;
        publisher->slots[i].slot_in_use = 0;
    }
}

int publisher_subscribe(Publisher_t *publisher, SubscriberCallback cb, void *user_data)
{
    if(!publisher || !cb)
        return -1;

    for(int i =0;i<MAX_SUBSCRIBERS;i++)
    {
        if(!publisher->slots[i].slot_in_use)
        {
            publisher->slots[i].cb =cb;
            publisher->slots[i].user_data = user_data;
            publisher->slots[i].slot_in_use=1;
            return 0;
        }      
    }

    return -1;
}

/* unsubscribe a subscriber based on callback and user data */
int publisher_unsubscribe(Publisher_t *publisher, SubscriberCallback cb,void *user_data)
{
    if(!publisher && !cb)
        return -1;

    for(int i=0;i<MAX_SUBSCRIBERS;i++)
    {
        if (publisher->slots[i].cb == cb && publisher->slots[i].user_data == user_data && publisher->slots[i].slot_in_use)
        {
           publisher->slots[i].cb = NULL;
           publisher->slots[i].user_data = NULL;
           publisher->slots[i].slot_in_use = 0;
        }
    }
    return -1; // not found element to be deleted
}

void publisher_notify(Publisher_t *publisher, const SensorEvent_t *event)
{
    if(!publisher || !event)
        return;

    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        if(publisher->slots[i].slot_in_use && publisher->slots[i].slot_in_use)
        {
            publisher->slots[i].cb(event,publisher->slots[i].user_data);
        }
    }
}

/* Example subcriber callback */
void logger_callback(const SensorEvent_t *event, void *user_data)
{
    (void *) user_data;
    printf("[LOGGER] Logged the values : temperature %d, sensor id %d at timestamp %lu\n", event->temperature, event->sensor_id, event->timestamp);
}

void alarm_callback(const SensorEvent_t *event, void *user_data)
{
    int threshold_value = *(int *)  user_data;

    if (event->temperature > threshold_value)
    {
         printf("[ALARM] the value %d is greater than threshold value %d on sensor_id %d at timestamp %lu.\n", event->temperature, threshold_value,
            event->sensor_id, event->timestamp);
    }
}

void display_callback(const SensorEvent_t *event, void *user_data)
{
    const char *name = (const char *) user_data;
    printf("[%s] displays temperature %d on sensor id %d at timestamp %lu.\n", name, event->temperature,event->sensor_id,event->timestamp);
}

/* actual use of everything above */
int main(void)
{
    Publisher_t sensor_publisher;
    int alarm_threshold = 18;

    publisher_initialize(&sensor_publisher);

    SensorEvent_t sensor_event_1;
    SensorEvent_t sensor_event_2;

    publisher_subscribe(&sensor_publisher, logger_callback, NULL);
    publisher_subscribe(&sensor_publisher,alarm_callback,&alarm_threshold);
    publisher_subscribe(&sensor_publisher,display_callback,"LG");

    //Fill in the sensor_event objects
    sensor_event_1 = (SensorEvent_t) {10,45,20260305};
    sensor_event_2 = (SensorEvent_t) {40,46,20260306};

    printf("Published broadcasts sensor_event_1\n");
    publisher_notify(&sensor_publisher,&sensor_event_1);

    printf("Published broadcasts sensor_event_2\n");
    publisher_notify(&sensor_publisher,&sensor_event_2);


    printf("Publisher unsubscribes logger \n");
    publisher_unsubscribe(&sensor_publisher,logger_callback,NULL);

    return 0;
}