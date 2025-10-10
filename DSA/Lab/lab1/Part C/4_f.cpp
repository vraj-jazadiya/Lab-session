#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 3;
    int val = 99;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = val;
    n++;

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\ndone" << endl;
    return 0;
}
