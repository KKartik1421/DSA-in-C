#include <stdio.h>
#define MAX 5 // Size of the Circular Queue

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* q) {
    if ((q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1))) {
        return 1;
    }
    return 0;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to insert an element into the circular queue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }

    if (q->front == -1) { // First element being inserted
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }

    int data = q->items[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    return data;
}

// Function to display the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX; // Circular increment
    }
    printf("%d\n", q->items[i]); // Print the last element
}

// Main function
int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    printf("Deleted element: %d\n", dequeue(&q));

    enqueue(&q, 60);
    display(&q);

    return 0;
}