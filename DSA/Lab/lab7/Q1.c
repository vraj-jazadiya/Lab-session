#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue
{
    int *Q;
    int size;
    int front;
    int rear;
};

int isEmpty(struct queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

int isFull(struct queue *q)
{
    return (q->rear == q->size - 1);
}

void enqueue(struct queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue Overflow! Cannot enqueue %d\n", x);
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->Q[q->rear] = x;
    printf("Enqueued: %d\n", x);
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = q->Q[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return value;
}

int peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->Q[q->front];
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->Q[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.size = MAX;
    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size * sizeof(int));

    if (!q.Q) {
        printf("Memory allocation failed\n");
        return 1;
    }

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Front element: %d\n", peek(&q));

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);

    free(q.Q);

    return 0;
}
