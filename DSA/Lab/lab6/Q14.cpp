#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &expr)
{
    stack<char> stk;

    for (int i = 0; i < expr.length(); ++i)
    {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stk.empty())
                return false;

            char top = stk.top();
            stk.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return stk.empty();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression))
        cout << "Balanced parentheses.\n";
    else
        cout << "Unbalanced parentheses.\n";

    return 0;
}
