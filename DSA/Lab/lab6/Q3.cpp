// a stack using an array
#include <iostream>
using namespace std;

#define SIZE 100

class stack
{
private:
    int arr[SIZE];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == SIZE - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << "pushed to stack" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underFlow" << endl;
        }
        else
        {
            cout << "popped Element : " << arr[top--] << endl;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "stack empty" << endl;
        }
        else
        {
            cout << "top Element : " << arr[top] << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "stack empty" << endl;
        }
        else
        {
            cout << "stack elemnt:" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    stack s;
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