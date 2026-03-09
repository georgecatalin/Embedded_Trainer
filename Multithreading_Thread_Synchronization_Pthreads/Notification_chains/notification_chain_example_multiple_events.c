/*
This example resembles a real one, with a publisher supporting multiple events.

This is common in real systems. One publisher can generate multiple kinds of events, and subscribers care usually only about a few of them.

Example event types:
- temperature update
- battery low
- sensor error

Subscribers choose which event type they want to receive.



*/

#include <stdio.h>

#define MAX_SUBSCRIBERS 20

typedef enum EventType
{
    EVENT_TEMPERATURE_UPDATE,
    EVENT_BATTERY_LOW,
    EVENT_SENSOR_ERROR
} EventType_t;

typedef struct Event
{
    EventType_t event_type;
    int sensor_id;
    unsigned long timestamp;

    union  //The union lets you store different type of data depending on the event type
    {
        int temperature;
        int battery_level;
        int error_code;
    } data;
    
} Event_t;

typedef void (*SubscriberCallback) (const Event_t *event, void *user_data);

typedef struct SubscriberSlot
{
    SubscriberCallback callback;
    void *user_data;
    EventType_t event_type;
    int is_slot_used;
} SubscriberSlot_t;

typedef struct Publisher
{
    SubscriberSlot_t slots[MAX_SUBSCRIBERS];
} Publisher_t;

void publisher_initialize(Publisher_t *publisher)
{
    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        publisher->slots[i].callback = NULL;
        publisher->slots[i].user_data = NULL;
        publisher->slots[i].event_type = EVENT_TEMPERATURE_UPDATE;
        publisher->slots[i].is_slot_used = 0;
    }
}

int publisher_subscribe(Publisher_t *publisher, SubscriberCallback callback, void * user_data, EventType_t event_type)
{
    if(!publisher || !callback)
        return -1;

    for (int i = 0; i < MAX_SUBSCRIBERS; i++)
    {
        if(!publisher->slots[i].is_slot_used)
        {
            publisher->slots[i].callback = callback;
            publisher->slots[i].user_data = user_data;
            publisher->slots[i].event_type = event_type;
            publisher->slots[i].is_slot_used = 1;

            return 0;
        }
    }  
    return -1; //there is no place available to hold the newcomer

}

/* notify the subscribers whose event type matches*/
void publisher_notify(Publisher_t *publisher, Event_t *event)
{
    for(int i=0;i<MAX_SUBSCRIBERS; i++)
    {
        if(publisher->slots[i].is_slot_used && publisher->slots[i].event_type == event->event_type)
        {
            publisher->slots[i].callback(event,publisher->slots[i].user_data);
        }
    }
}

/* write examples of callback functions */
void temperature_logger(const Event_t *event, void * user_data)
{
    (void *) user_data;
    printf("[TEMPERATURE] Logged temperature %d on sensor id %d at timestamp %lu. \n", 
        event->data.temperature, event->sensor_id, event->timestamp);
}

void battery_metter(const Event_t *event, void * user_data)
{
    (void *) user_data;
    printf("[BATTERY] battery level %d on the sensor id %d .\n", event->data.battery_level, event->sensor_id);
}

void sensor_error(const Event_t *event, void *user_data)
{
    (void *) user_data;
    printf("[SENSOR ERROR] Sensor id %d has error code %d \n", event->sensor_id, event->data.error_code);
}

/* real use of everything */
int main(void)
{
    Publisher_t sensor_publisher;

    Event_t temp_event;
    Event_t battery_event;
    Event_t error_event;
    Event_t error_event_2;

    publisher_initialize(&sensor_publisher);

    publisher_subscribe(&sensor_publisher, temperature_logger, NULL, EVENT_TEMPERATURE_UPDATE);
    publisher_subscribe(&sensor_publisher, battery_metter,NULL, EVENT_BATTERY_LOW);
    publisher_subscribe(&sensor_publisher,sensor_error,NULL,EVENT_SENSOR_ERROR);

    //fill in the event objects
    temp_event = (Event_t) {.event_type = EVENT_TEMPERATURE_UPDATE, .sensor_id = 1, .timestamp =2026030901, .data.temperature=20 };
    battery_event = (Event_t) {.event_type = EVENT_BATTERY_LOW,.sensor_id = 2, .timestamp = 2026030801, .data.battery_level=1};
    error_event = (Event_t) {.event_type = EVENT_SENSOR_ERROR, .sensor_id =3, .timestamp = 2026030802, .data.error_code = 15541};
    error_event_2 = (Event_t) {.event_type = EVENT_SENSOR_ERROR, .sensor_id =4, .timestamp = 2026030802, .data.error_code = 1123};

    publisher_notify(&sensor_publisher,&error_event);


    return 0;
}