#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;    
        cout << x << " pushed to stack" << endl;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack Empty" << endl;
            return -1; 
        }
        Node *ptr = top;
        int poppedValue = top->data;
        top = top->next;
        delete ptr;
        cout << "Popped element: " << poppedValue << endl;
        return poppedValue;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node *p = top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int c, x;
    do
    {
        cout << "\nStack Menu\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (c != 4);

    return 0;
}
