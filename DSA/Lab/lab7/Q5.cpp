#include <iostream>
using namespace std;

#define max 10

struct element
{
    int data;
    int priority;
};

element pq[max];
int size = 0;

void enqueue(int val, int prio)
{
    if (size == max)
    {
        cout << "queue overflow !\n";
        return;
    }
    pq[size].data = val;
    pq[size].priority = prio;
    size++;
    cout << val << " added with priority " << prio << "\n";
}

void dequeue()
{
    if (size == 0)
    {
        cout << "queue underflow !\n";
        return;
    }

    int highest = 0;
    for (int i = 1; i < size; i++)
    {
        if (pq[i].priority > pq[highest].priority)
        {
            highest = i;
        }
    }

    cout << pq[highest].data << " removed (highest priority " << pq[highest].priority << ")\n";

    for (int i = highest; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }
    size--;
}

void peek()
{
    if (size == 0)
    {
        cout << "queue is empty\n";
        return;
    }

    int highest = 0;
    for (int i = 1; i < size; i++)
    {
        if (pq[i].priority > pq[highest].priority)
        {
            highest = i;
        }
    }

    cout << "front: " << pq[highest].data << " (priority " << pq[highest].priority << ")\n";
}

void display()
{
    if (size == 0)
    {
        cout << "queue is empty\n";
        return;
    }

    cout << "queue: ";
    for (int i = 0; i < size; i++)
    {
        cout << pq[i].data << ":" << pq[i].priority << "  ";
    }
    cout << "\n";
}

int main()
{
    int choice, val, prio;
    while (1)
    {
        cout << "\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n";
        cout << "enter yr choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter value: ";
            cin >> val;
            cout << "enter priority: ";
            cin >> prio;
            enqueue(val, prio);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "exit\n";
            return 0;
        default:
            cout << "invalid choice !\n";
        }
    }
    return 0;
}
