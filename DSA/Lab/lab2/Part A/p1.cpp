#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cout << "enter num of rows: ";
    cin >> row;
    cout << "enter num of cols: ";
    cin >> col;

    int ar1[row][col], ar2[row][col], i, j, ar3[row][col];

    cout << "\nArray A : \n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << "index " << i << j << " : ";
            cin >> ar1[i][j];
        }
        cout << endl;
    }

    cout << "\nArray B : \n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << "index " << i << j << " : ";
            cin >> ar2[i][j];
        }
        cout << endl;
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << ar1[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << ar2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAddition Matrix C : \n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            ar3[i][j] = ar1[i][j] + ar2[i][j];
            cout << ar3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
