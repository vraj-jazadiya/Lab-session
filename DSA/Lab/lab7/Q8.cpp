#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;
void enqueue1(int value)
{
    if (rear1 + 1 == rear2)
    {
        printf("\nQueue Overflow! -> q1\n");
        return;
    }
    if (front1 == -1)
        front1 = 0;
    arr[++rear1] = value;
    printf("Inserted %d -> q1\n", value);
}

void enqueue2(int value)
{
    if (rear2 - 1 == rear1)
    {
        printf("\nQueue Overflow! -> q2\n");
        return;
    }
    if (front2 == MAX)
        front2 = MAX - 1;
    arr[--rear2] = value;
    printf("Inserted %d -> q2\n", value);
}

void dequeue1()
{
    if (front1 == -1 || front1 > rear1)
    {
        printf("\nQ1 Underflow!\n");
        return;
    }
    printf("Deleted %d from Q1\n", arr[front1++]);
    if (front1 > rear1)
        front1 = rear1 = -1;
}

void dequeue2()
{
    if (front2 == MAX || front2 < rear2)
    {
        printf("\nQ2 Underflow!\n");
        return;
    }
    printf("Deleted %d -> q2\n", arr[front2--]);
    if (front2 < rear2)
        front2 = rear2 = MAX;
}

void display1()
{
    if (front1 == -1)
    {
        printf("\nQueue 1 is empty.\n");
        return;
    }
    printf("\nQueue 1: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2()
{
    if (front2 == MAX)
    {
        printf("\nQueue 2 is empty.\n");
        return;
    }
    printf("\nQueue 2: ");
    for (int i = front2; i >= rear2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue in Queue 1");
        printf("\n2. Enqueue in Queue 2");
        printf("\n3. Dequeue from Queue 1");
        printf("\n4. Dequeue from Queue 2");
        printf("\n5. Display Queue 1");
        printf("\n6. Display Queue 2");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue1(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue2(value);
            break;
        case 3:
            dequeue1();
            break;
        case 4:
            dequeue2();
            break;
        case 5:
            display1();
            break;
        case 6:
            display2();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
