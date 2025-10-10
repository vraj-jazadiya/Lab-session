#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int x)
{
    if (top == SIZE - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        stack[++top] = x;
        printf("%d pushed \n", x);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("popped ele: %d\n", stack[top--]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("top ele: %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack elmt : ");
        int i;
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice , x;
    while (1)
    {
        printf("\nStack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your chc: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter x to push: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exit\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
