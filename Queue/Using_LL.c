#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void enqueue(queue *q, int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    if (q->rear == NULL) {
        // Queue is empty
        q->front = new_node;
        q->rear = new_node;
    } else {
        // Add to the end of the queue
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicate that the queue is empty
    }

    node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        // If the queue is now empty, update rear
        q->rear = NULL;
    }

    free(temp);
    return value;
}

void displayQueue(queue *q) {
    node *temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    queue q;
    q.front = NULL;
    q.rear = NULL;
    int n_size, choice, value;

    printf("How many elements do you want to insert initially: ");
    scanf("%d", &n_size);
    
    for (int i = 1; i <= n_size; i++) {
        printf("Please enter value %d: ", i);
        scanf("%d", &value);
        enqueue(&q, value);
    }
    
    printf("The queue has been created.\n");
    displayQueue(&q);
    
    while (1) {
        printf("Do you want to insert (1) or delete (2) an element? (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(&q, value);
            printf("Inserted %d into the queue.\n", value);
        } else if (choice == 2) {
            value = dequeue(&q);
            if (value != -1) {
                printf("Deleted %d from the queue.\n", value);
            }
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        displayQueue(&q);
    }
    
    return 0;
}
