#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void enqueue(int x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    cout << x << " added\n";
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "queue underflow !\n";
        return;
    }

    node *temp = front;
    cout << front->data << " removed\n";
    front = front->next;

    if (front == NULL)
    {
        rear = NULL; // reset rear too when queue becomes empty
    }

    delete temp;
}

void peek()
{
    if (front == NULL)
    {
        cout << "queue is empty\n";
    }
    else
    {
        cout << "front: " << front->data << "\n";
    }
}

void display()
{
    if (front == NULL)
    {
        cout << "queue is empty\n";
    }
    else
    {
        node *temp = front;
        cout << "queue: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main()
{
    int choice, val;
    while (1)
    {
        cout << "\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n";
        cout << "enter yr choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "add: ";
            cin >> val;
            enqueue(val);
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
