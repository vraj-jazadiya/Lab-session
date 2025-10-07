#include <iostream>
using namespace std;

class Twostacks
{
private:
    int *arr;
    int size;
    int top1, top2;

public:
    Twostacks(int n)
    {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    ~Twostacks()
    {
        delete[] arr;
    }

    void push1(int x)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stack1 is full" << endl;
            return;
        }
        arr[++top1] = x;
        cout << "1pushed: " << x << endl;
    }

    void push2(int x)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stack2 is full" << endl;
            return;
        }
        arr[--top2] = x;
        cout << "2pushed: " << x << endl;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack1 is empty" << endl;
            return;
        }
        cout << arr[top1--] << " popped from stack1" << endl;
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack2 is empty" << endl;
            return;
        }
        cout << arr[top2++] << " popped from stack2" << endl;
    }
    void display1()
    {
        if (top1 == -1)
        {
            cout << "Stack1 is empty\n";
            return;
        }
        cout << "Stack1 elements: ";
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    void display2()
    {
        if (top2 == size)
        {
            cout << "Stack2 is empty\n";
            return;
        }
        cout << "Stack2 elements: ";
        for (int i = size - 1; i >= top2; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main()
{
    Twostacks ts(10); 

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    ts.display1();
    ts.display2();

    ts.pop1();
    ts.pop2();

    ts.display1();
    ts.display2();

 
    ts.push1(25);
    ts.push1(35);
    ts.push1(45);
    ts.push1(55);
    ts.push1(65);

    ts.push2(30);
    ts.push2(40);

    return 0;
}
