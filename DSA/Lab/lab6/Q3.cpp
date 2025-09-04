// a stack using an array

#include <iostream>
using namespace std;

#define SIZE 100

class Stack
{
private:
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack OverFlow" << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << "Pushed to stack" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underFlow" << endl;
        }
        else
        {
            cout << "Popped Element : " << arr[top--] << endl;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            cout << "Top Element : " << arr[top] << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            cout << "Stack Elements:" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();
    s.peek();
    s.pop();
    s.display();

    return 0;
}