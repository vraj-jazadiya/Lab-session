#include <iostream>
using namespace std;

int main()
{
    int arr[10][10], row, col, i, j;

    cout << "enter num of rows: ";
    cin >> row;
    cout << "enter num of cols: ";
    cin >> col;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << "index " << i << j << " : ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
