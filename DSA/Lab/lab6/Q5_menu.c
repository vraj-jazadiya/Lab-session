// Implement a stack using a singly linked list with push, pop, and display in C.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", x);
}

void pop()
{
    if (top == NULL)
    {
        printf("stack underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("popped elemnt: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

