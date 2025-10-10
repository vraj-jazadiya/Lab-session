#include <iostream>
using namespace std;

int main()
{
    int arr[10][10], row, col, i, j, id = 0;

    cout << "enter num of rows: ";
    cin >> row;
    cout << "enter num of cols: ";
    cin >> col;

    if (row != col)
    {
        cout << "not a squere matrix, so no identity matrix !!";
        goto end;
    }

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
        if (arr[i][i] == 1)
        {
            id++;
        }
    }

    if (id != 0)
    {
        cout << "identity matrix !!";
    }
    else
    {
        cout << "not an identity matrix !!";
    }

end:
    return 0;
}
