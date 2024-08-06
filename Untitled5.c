#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() { return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)); }
int isEmpty() { return (front == -1); }

void enqueue(int value) {
    if (isFull()) { printf("Queue is full\n"); }
    else {
        if (front == -1) { front = 0; }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void dequeue() {
    if (isEmpty()) { printf("Queue is empty\n"); }
    else {
        printf("%d dequeued from queue\n", queue[front]);
        if (front == rear) { front = rear = -1; }
        else { front = (front + 1) % MAX_SIZE; }
    }
}

void display() {
    int i;
    if (isEmpty()) { printf("Queue is empty\n"); }
    else {
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    
    dequeue();
    display();

    return 0;
}
