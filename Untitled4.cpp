#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function to create a new circular queue
CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->front == -1;
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to add an element to the circular queue
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Function to remove an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int removedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    printf("%d dequeued from queue.\n", removedItem);
    return removedItem;
}

// Function to get the front element of the circular queue without removing it
int front(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Function to print the circular queue
void printQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->items[i]);
    }
    printf("%d\n", queue->items[i]);
}

// Function to deallocate memory for the circular queue
void freeCircularQueue(CircularQueue* queue) {
    free(queue);
}

int main() {
    CircularQueue* queue = createCircularQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    printf("Front element: %d\n", front(queue));

    freeCircularQueue(queue);
    return 0;
}

