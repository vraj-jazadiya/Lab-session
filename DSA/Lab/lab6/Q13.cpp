#include <iostream>
using namespace std;

#define MAX 100

class stack
{
    char arr[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << "stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow\n";
            return '\0';
        }
        return arr[top--];
    }
    char peek()
    {
        if (isEmpty())
            return '\0';
        return arr[top];
    }
};

bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool areParenthesesBalanced(string expr) {
    stack s;

    for (size_t i = 0; i < expr.size(); i++) {
        char x = expr[i];
        if (x == '(' || x == '{' || x == '[') {
            s.push(x);
        }
        else if (x == ')' || x == '}' || x == ']') {
            if (s.isEmpty() || !isMatchingPair(s.pop(), x)) {
                return false;
            }
        }
    }

    return s.isEmpty();
}


int main() {
    string expr;
    cout << "an expression: ";
    getline(cin, expr);

    if (areParenthesesBalanced(expr)) {
        cout << "balanced\n";
    }
    else {
        cout << "NOT balanced\n";
    }

    return 0;
}
