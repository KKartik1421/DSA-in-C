#include <stdio.h>

#define MAX 100  // Maximum size of the queue

int queue[MAX];  // Queue array
int front = -1, rear = -1;  // Front and rear pointers

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Function to insert (enqueue) an element in the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full, cannot insert element.\n");
        return;
    }
    if (front == -1) front = 0;  // First insertion
    rear++;
    queue[rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete (dequeue) an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty, cannot delete element.\n");
        return;
    }
    printf("Deleted %d from the queue.\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;  // Queue becomes empty
    }
}

// Function to search for an element in the queue
void search(int value) {
    if (front == -1) {
        printf("Queue is empty, no elements to search.\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        if (queue[i] == value) {
            printf("Element %d found at position %d.\n", value, i - front + 1);
            return;
        }
    }
    printf("Element %d not found in the queue.\n", value);
}

int main() {
    int choice, value, n, i;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("Enter the elements of the queue (use 0 for empty spots):\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &queue[i]);
        if (queue[i] != 0 && front == -1) {
            front = i;  // Set front to the first non-zero element
        }
        if (queue[i] != 0) {
            rear = i;  // Set rear to the last non-zero element
        }
    }

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Display Queue\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 3:
                dequeue();
                display();
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
