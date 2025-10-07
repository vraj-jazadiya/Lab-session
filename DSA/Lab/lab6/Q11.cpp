#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string input;
    cout << "Enter your string: " << endl;
    getline(cin, input);

    stack<char> stk;

    for (int i = 0; i < input.length(); ++i)
    {
        stk.push(input[i]);
    }

    string reversed;
    while (!stk.empty())
    {
        reversed += stk.top();
        stk.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}