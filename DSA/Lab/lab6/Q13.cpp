#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack()
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
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
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
    Stack s;

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
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (areParenthesesBalanced(expr)) {
        cout << "The expression has balanced parentheses.\n";
    }
    else {
        cout << "The expression does NOT have balanced parentheses.\n";
    }

    return 0;
}
