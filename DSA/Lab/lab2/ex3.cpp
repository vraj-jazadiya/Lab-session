#include <iostream>
using namespace std;

int main()
{
    int arr[10][10], row, col, i, j;

    cout << "enter num of rows: ";
    cin >> row;
    cout << "enter num of cols: ";
    cin >> col;

    if (row == col)
    {
        cout << "\nsquere matrix !!";
    }
    else
    {
        cout << "\nNot a squere matrix !!!";
    }
    return 0;
}
