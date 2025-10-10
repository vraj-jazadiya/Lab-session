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

class stack
{
private:
    Node *top;

public:
    stack()
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
            cout << "stack Empty" << endl;
            return -1; 
        }
        Node *ptr = top;
        int poppedValue = top->data;
        top = top->next;
        delete ptr;
        cout << "popped elemnt: " << poppedValue << endl;
        return poppedValue;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "stack elemnts: ";
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
    stack s;
    int c, x;
    do
    {
        cout << "\nstack Menu\n";
        cout << "1. push\n2. pop\n3. display\n4. exit\n";
        cout << "enter yr chic: ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "push: ";
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
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (c != 4);

    return 0;
}
