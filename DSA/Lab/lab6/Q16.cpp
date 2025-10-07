#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 1;
    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(const string &infix)
{
    stack<char> stk;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else if (isOperator(ch))
        {
            while (!stk.empty() && precedence(stk.top()) >= precedence(ch))
            {
                if (ch == '^' && stk.top() == '^')
                    break;
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}
int main()
{
    string infixExp;
    cout << "Enter an infix expression: ";
    getline(cin, infixExp);

    string postfixExp = infixToPostfix(infixExp);
    cout << "Postfix expression: " << postfixExp << endl;

    return 0;
}
