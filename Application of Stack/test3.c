#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x) {
    if(x=='-'){
        return 0;
    }else if(x=='+'){
        return 1;
    }else if(x=='*'){
        return 2;
    }else if(x=='/'){
        return 3;
    }
}

int main() {
    int i;
    char exp[100],a[20];
    char x;
    int j=0;
    printf("Enter the expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            a[j++]=exp[i];
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                a[j++]=pop();
            }
            push(exp[i]);
        }
    }

    while (top != -1) {
        a[j++]=pop();
    }
    a[j]='\0';
    for(j=0;exp[j]!='\0';j++){
        printf("%c",a[j]);
    }

    return 0;
}