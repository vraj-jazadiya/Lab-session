#include <iostream>
using namespace std;

int main()
{
    int mat[2][3][4], i, j, k;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                cout << "enter ele for " << i << j << k << " : ";
                cin >> mat[i][j][k];
            }
        }
        cout << endl;
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                cout << mat[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (i = 0; i < 2; i++)
    {
        cout << "2D matrix " << i + 1 << endl;
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                cout << mat[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}