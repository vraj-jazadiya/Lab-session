#include <iostream>
using namespace std;

#define max 5

int dq[max];
int front = -1;
int rear = -1;

void insertfront(int x)
{
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        cout << "queue overflow !\n";
    }
    else if (front == -1)
    {
        front = rear = 0;
        dq[front] = x;
    }
    else if (front == 0)
    {
        front = max - 1;
        dq[front] = x;
    }
    else
    {
        front = front - 1;
        dq[front] = x;
    }
    cout << x << " added at front\n";
}

void insertrear(int x)
{
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        cout << "queue overflow !\n";
    }
    else if (front == -1)
    {
        front = rear = 0;
        dq[rear] = x;
    }
    else if (rear == max - 1)
    {
        rear = 0;
        dq[rear] = x;
    }
    else
    {
        rear = rear + 1;
        dq[rear] = x;
    }
    cout << x << " added\n";
}

void deletefront()
{
    if (front == -1)
    {
        cout << "queue underflow !\n";
    }
    else
    {
        cout << dq[front] << " removed\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == max - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
}

void deleterear()
{
    if (front == -1)
    {
        cout << "queue underflow !\n";
    }
    else
    {
        cout << dq[rear] << " removed\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = max - 1;
        }
        else
        {
            rear = rear - 1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        cout << "queue is empty\n";
    }
    else
    {
        cout << "queue: ";
        int i = front;
        while (true)
        {
            cout << dq[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % max;
        }
        cout << "\n";
    }
}

int main()
{
    int choice, val;
    while (1)
    {
        cout << "\n1.insert front\n2.insert rear\n3.delete front\n4.delete rear\n5.display\n6.exit\n";
        cout << "enter yr choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "add: ";
            cin >> val;
            insertfront(val);
            break;
        case 2:
            cout << "add: ";
            cin >> val;
            insertrear(val);
            break;
        case 3:
            deletefront();
            break;
        case 4:
            deleterear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "exit\n";
            return 0;
        default:
            cout << "invalid choice !\n";
        }
    }
    return 0;
}
