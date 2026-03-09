/*

A publisher produces events. 
A subscriber says "CALL ME WHEN THAT EVENT HAPPENS".
A notification chain is the list of subscribers the Publisher has to walk through when notifying that a certain event occurred.

Because C programming language is simple and it has no built-in classes or signal/slots mechanisms we are going to use the following for the practical implementation
of notification chains:
- a function pointer for the callback
- a linked list or an array to store the subscribers
- a data structure to the used for the event

The idea:
Suppose you have a temperature sensor module.
* The sensor detects a new temperature.
* Several parts of the program are concerned:
    - logger
    - display
    - alarm system

You do not want the sensor code to know about these modules directly.

Instead you wish to implement a publisher/subscriber architecture concept.
1. the sensor is the Publisher
2. logger/display/alarm systems are the subscribers
3. each subscriber registers a callback function
4. when new data arrives, the sensor (publisher) call each registered callback function.

This is how the publisher-subscriber pattern works.

Why use Publisher-subscriber pattern?
Without this pattern, the code becomes tightly coupled

void sensor_update(int new_temp)
{
    logger_log(new_temp);
    display_show(new_temp);
    alarm_check(new_temp);
}

this works , but the sensor program would be hard wired to the other program modules.

instead we are looking for a decoupled architecture.

With publisher-subscriber

void sensor_update(int new_temp)
{
    notify_all_subscribers(new_temp);
}

Now, in this decoupled pattern the sensor program does not know or care who is listening.

This provides:
- better modularity
- easier extension
- less dependency between the modules

Core building blocks in C

In C programming language, the most common implementation uses:
Callback type

a function pointer that all subscribers must match:

    typedef void (* SubscriberCallback) (int value, void *user_data);

where :
- callback gets the published value
- callback also gets user_data which is a custom pointer for subscriber context

SUBSCRIBER

A structure holding one callback

typedef struct Subscriber
{
    SubscriberCallback callback;
    void *user_data;
    Subscriber_t * next;
} Subscriber_t;

PUBLISHER

A structure holding the head of the subscriber chain.

typedef struct Publisher
{
    Subscriber_t *head;
} Publisher_t;

*/

#include <stdio.h>
#include <stdlib.h>

typedef void (*SubscriberCallback) (int value, void *user_data);

typedef struct Subscriber Subscriber_t;

struct Subscriber
{
    SubscriberCallback callback;
    void *user_data;
    Subscriber_t *next;
};

typedef struct Publisher
{
    Subscriber_t *head;
}Publisher_t;

/* INitialize publisher */
void initialize_publisher(Publisher_t *publisher)
{
    publisher->head = NULL;
}

/* Subscribe a new callback */
int publisher_subscribe(Publisher_t *publisher, SubscriberCallback callback, void *user_data)
{
    Subscriber_t * node = (Subscriber_t *) malloc(sizeof(Subscriber_t));

    if (!node)
    {
        return -1; //memory allocation has failed
    }
    
    node->callback = callback;
    node->user_data = user_data;
    node->next = publisher->head;
    publisher->head = node;

    return 0;
 }

 /* Notify all subscribers */
 void publisher_notifies(Publisher_t *publisher, int value)
 {
    Subscriber_t *this_node = publisher->head;

    while(this_node)
    {
        this_node->callback(value, this_node->user_data);
        this_node = this_node->next;
    }
 }

 /* Free all subscribers */
 void publisher_cleansup(Publisher_t *publisher)
 {
    Subscriber_t *this_node = publisher->head;

    while(this_node)
    {
        Subscriber_t *next = this_node->next;
        free(this_node);
        this_node = next;
    }

    publisher->head = NULL;
 }

 /* Example for subscriber callbacks */
 void logger_callback(int value, void *user_data)
 {
    (void *) user_data;
    printf("[LOGGER] value is %d\n",value);
 }

 void alarm_callback(int value, void *user_data)
 {
    int threshold = *(int *) user_data;

    if(value > threshold)
    {
        printf("[ALARM] Value %d is greater than threshold %d.\n", value, threshold);
    }
 }

 void display_callback(int value, void *user_data)
 {
    const char *display_name = (const char *) user_data;

    printf("[DISPLAY] %s shows value %d\n", display_name, value);
 }


 /* Example of actual usage */

 int main(void)
 {
    Publisher_t sensor;
    int alarm_threshold_value = 19;

    /* Initialize publisher */
    initialize_publisher(&sensor);

    /* Subscribe subscribers */
    publisher_subscribe(&sensor, logger_callback, NULL);
    publisher_subscribe(&sensor,alarm_callback,&alarm_threshold_value);
    publisher_subscribe(&sensor,display_callback,"LCD");

    /* Notify subscribers */
    printf("Sensor publisher notifies value 10:\n");
    publisher_notifies(&sensor,10);

    printf("Sensor publisher notifies value 20:\n");
    publisher_notifies(&sensor,20);

    /* Clears the subscribers */
    publisher_cleansup(&sensor);


    return 0;
 }