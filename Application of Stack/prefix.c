#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, char op) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = op;
    }
}

char pop(struct Stack* stack) {
    return isEmpty(stack) ? '\0' : stack->arr[stack->top--];
}

int precedence(char op) {
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    struct Stack* stack = createStack();
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->arr[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(stack->arr[stack->top]) >= precedence(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    free(stack);
}

// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(const char* infix, char* prefix) {
    char reversedInfix[MAX];
    char postfix[MAX];

    // Step 1: Reverse the infix expression
    reverse(strcpy(reversedInfix, infix));

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; reversedInfix[i]; i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    // Step 3: Convert reversed infix to postfix
    infixToPostfix(reversedInfix, postfix);

    // Step 4: Reverse the postfix expression to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
