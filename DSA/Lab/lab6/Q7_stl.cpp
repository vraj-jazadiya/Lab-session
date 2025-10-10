#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << " Pushed 10 , 20 , 30; " << endl;

    cout << "stack size : " << stk.size() << endl;
    cout << "is stack empty ? " << (stk.empty() ? "yes" : "No") << endl;

    if (!stk.empty()){
        cout << "top Element: " << stk.top() << endl;
    }
    while (!stk.empty()) {
        cout << "popping element: " << stk.top() << "\n";
        stk.pop();
    }


    cout << "stack size : " << stk.size() << endl;
    cout << "is stack empty?" << (stk.empty() ? "yes" : "No") << endl;

    return 0;
}
