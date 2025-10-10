#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n;
    cout << "enter size for 3D matrix : ";
    cin >> n;
    int mat[n][n][n], sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                cout << "enter elem for " << i << j << k << " : ";
                cin >> mat[i][j][k];
                sum = sum + mat[i][j][k];
            }
        }
        cout << endl;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                cout << mat[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "\nSum: " << sum;
    return 0;
}