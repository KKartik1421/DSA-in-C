#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isEmpty(struct Node* top) {
    return !top;
}

void push(struct Node** top, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory error\n"); return; }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", val);
}

int pop(struct Node** top) {
    if (isEmpty(*top)) { printf("Stack Underflow!\n"); return -1; }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int search(struct Node* top, int val) {
    for (struct Node* current = top; current; current = current->next) {
        if (current->data == val) return 1;
    }
    return 0;
}

void printStack(struct Node* top) {
    if (isEmpty(top)) { printf("Stack is empty\n"); return; }
    for (struct Node* current = top; current; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int numElements, value, choice;
    
    printf("How many elements to insert? ");
    scanf("%d", &numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(&top, value);
    }

    printf("Search for an element? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter element to search: ");
        scanf("%d", &value);
        printf(search(top, value) ? "Found %d\n" : "Not found %d\n", value);
    }

    printStack(top);

    while (1) {
        printf("\nPush(1), Pop(2), Exit(0): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&top, value);
            printStack(top);
        } else if (choice == 2) {
            printf("Enter value to pop: ");
            scanf("%d", &value);
            if (!isEmpty(top) && top->data == value) {
                pop(&top);
                printf("%d popped\n", value);
                printStack(top);
            } else {
                printf("Only top element can be popped.\n");
            }
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
