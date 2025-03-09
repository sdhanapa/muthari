#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the queue

// Structure to represent the queue
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

// Function to initialize the queue
void InitQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front if the queue was empty
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void display(Queue *q){
    for(int i=q->front;i<MAX_SIZE;i++){
        printf("%d ",q->items[i]);
    }
    printf("\n");
}


void dequeue(Queue *q){
    printf("Dequeued: %d\n", q->items[q->front]);
    q->items[q->front] = 0;
    q->front++;
}
int main() {
    Queue q;
    InitQueue(&q);

    for(int i =0;i<=5;i++)
    enqueue(&q, i+10);
    display(&q); 
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q); 

    return 0;
}