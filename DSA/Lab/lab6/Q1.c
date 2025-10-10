#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("stack overflow\n");
    } else {
        stack[++top] = value;
        printf("%d pushed \n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("stack underflow\n");
    } else {
        printf("popped ele: %d\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        printf("top ele: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        printf("stack elmt : ");
        int i;
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
