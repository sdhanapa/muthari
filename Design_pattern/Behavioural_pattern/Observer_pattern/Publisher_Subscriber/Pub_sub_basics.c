#include<stdio.h>
#define MAX_SUB 10
// Write the C program to Create subscriber table during subscriber registration, notify all the subscriber and Deregister specific Subscriber.
typedef enum{
    EVENT_1,
    EVENT_2,
}EventType;

typedef void (*SubscriberCallback)(EventType event, void *data);

//Notification chain is important struct to create subscriber table with corresponding callback function.
typedef struct {
    SubscriberCallback subscriber[MAX_SUB];
    int count;    
}NotificationChain;

//register a subscribers
int register_subscriber(NotificationChain* chain, SubscriberCallback callback) {
    if (chain->count >= MAX_SUB) {
        return -1; // No more space for subscribers
    }

    chain->subscriber[chain->count] = callback;
    chain->count++;
    printf("Subscriber %d is Registered\n",chain->count);
    return 0; // Success
}

//De-register a subscribers
int deregister_subscriber(NotificationChain* chain, SubscriberCallback callback) {
    int i=0;
    printf("Received request for Degistering the subscriber %d\n",chain->count);
    for( i =1 ;i< chain->count;i++){
        if(chain->subscriber[i] == callback){
            break;
        }
    }
    i++;
    chain->count--;
    printf("Subscriber %d is De-Registered.\t Thank you\n",i);
    for(i;i<=chain->count;i++){
       
        chain->subscriber[i] = chain->subscriber[i+1];
    }

    return 0; // Success
}

void notify_subscribers_broadcast(NotificationChain *chain, EventType event, void* data ){
    for(int i=0; i< chain->count;i++){
    chain->subscriber[i](event,data);
    }
}

// Example subscriber callback function
void subscriber_callback_1(EventType event, void* data) {
    printf("Subscriber 1: Event %d occurred with data: %s\n", event, (char*)data);
}

void subscriber_callback_2(EventType event, void* data) {
    printf("Subscriber 2: Event %d occurred with data: %s\n", event, (char*)data);
}

void subscriber_callback_3(EventType event, void* data) {
    printf("Subscriber 3: Event %d occurred with data: %s\n", event, (char*)data);
}
void subscriber_callback_4(EventType event, void* data) {
    printf("Subscriber 4: Event %d occurred with data: %s\n", event, (char*)data);
}

int main() {
    NotificationChain chain;
    chain.count = 0;
    //init_notification_chain(&chain);

    // Register subscribers
    register_subscriber(&chain, subscriber_callback_1);
    register_subscriber(&chain, subscriber_callback_2);
    register_subscriber(&chain, subscriber_callback_3);
    register_subscriber(&chain, subscriber_callback_4);

    // Notify subscribers about an event
    char* event_data = "Event Data";
    notify_subscribers_broadcast(&chain, EVENT_1, event_data);
    deregister_subscriber(&chain, subscriber_callback_4);
    notify_subscribers_broadcast(&chain, EVENT_2, event_data);

    return 0;
}