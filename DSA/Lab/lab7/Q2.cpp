#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
private:
    Node *first;
    Node *rear;

public:
    Queue()
    {
        first = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return first == NULL;
    }

    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (isEmpty())
        {
            first = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << x << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }
        int val = first->data;
        Node *temp = first;
        first = first->next;
        delete temp;

        if (first == NULL)
            rear = NULL;

        return val;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return first->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = first;
        cout << "Queue elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
