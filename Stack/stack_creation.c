#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stack
struct stack {
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// Function to push an element into the stack
void push(struct stack *ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Function to pop the top element from the stack
int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Function to search for an element in the stack
int searchElement(struct stack *ptr, int val) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot search the stack\n");
        return 0;
    }

    int found = 0;
    for (int i = 0; i <= ptr->top; i++) {
        if (ptr->arr[i] == val) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Element %d found in the stack\n", val);
        return 1;
    } else {
        printf("Element %d not found in the stack\n", val);
        return 0;
    }
}

// Function to print all the elements of the stack
void printStack(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Current stack elements are:\n");
    for (int i = 0; i <= ptr->top; i++) {
        printf("%d\n", ptr->arr[i]);
    }
}


int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    // Ask user for the size of the stack
    printf("Enter the total size of the stack: ");
    scanf("%d", &sp->size);

    sp->top = -1;             
    sp->arr = (int *)malloc(sp->size * sizeof(int)); // Allocate memory for the stack elements
    
    printf("Stack has been created successfully\n");

    // Ask user how many elements they want to insert in the stack
    int numElements;
    printf("How many elements do you want to insert in the stack? ");
    scanf("%d", &numElements);

    // Ensure the user doesn't enter more than the stack size
    if (numElements > sp->size) {
        printf("You cannot insert more elements than the stack size!\n");
        return 1;
    }

    // Ask user to input elements into the stack
    printf("Please enter %d elements to push into the stack:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(sp, value);
    }

    // Ask user if they want to search for a specific element
    char searchChoice;
    printf("Do you want to search for an element in the stack? (y/n): ");
    scanf(" %c", &searchChoice);

    if (searchChoice == 'y' || searchChoice == 'Y') {
        int valueToSearch;
        printf("Enter the element you want to search: ");
        scanf("%d", &valueToSearch);
        searchElement(sp, valueToSearch);
    }

    // Allow the user to push or pop elements as needed
    while (1) {
        char actionChoice;
        printf("Do you want to push or pop an element? (p for push, o for pop, e to exit): ");
        scanf(" %c", &actionChoice);

        if (actionChoice == 'p' || actionChoice == 'P') {
            if (isFull(sp)) {
                printf("Stack is full, cannot push any more elements\n");
            } else {
                int valueToPush;
                printf("Enter the element you want to push: ");
                scanf("%d", &valueToPush);
                push(sp, valueToPush);
                printStack(sp);
            }
        } 
        else if (actionChoice == 'o' || actionChoice == 'O') {
            if (isEmpty(sp)) {
                printf("Stack is empty, cannot pop any elements\n");
            } else {
                int valueToPop;
                printf("Enter the element you want to pop (only top element can be popped): ");
                scanf("%d", &valueToPop);

                // Check if the user is trying to pop the top element
                if (sp->arr[sp->top] == valueToPop) {
                    pop(sp);
                    printf("Element %d has been popped from the stack\n", valueToPop);
                    printStack(sp);
                } else {
                    printf("Only the top element can be popped. You cannot pop an element from the middle of the stack.\n");
                }
            }
        } 
        else if (actionChoice == 'e' || actionChoice == 'E') {
            break; // Exit the loop
        }
    }

    // Free allocated memory
    free(sp->arr);
    free(sp);

    return 0;
}
