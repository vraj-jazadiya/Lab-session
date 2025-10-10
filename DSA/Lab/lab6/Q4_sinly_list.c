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

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    pop();
    pop();
    pop();

    return 0;
}
