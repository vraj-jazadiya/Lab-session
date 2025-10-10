#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n, p, q, r;
    cout << "3D matrix : ";
    cin >> n;
    int mat[n][n][n], el, flag = 0;

    cin >> el;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                cout << "enter ele for " << i << j << k << " : ";
                cin >> mat[i][j][k];
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
                if (mat[i][j][k] == el)
                {
                    flag++;
                    p = i;
                    q = j;
                    r = k;
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    if (flag != 0)
    {
        cout << "\nelement " << el << " is found";
        cout << "\nat layer: " << p << "\nrow: " << q << "\ncolumn: " << r;
    }
    else
    {
        cout << "\nelement " << el << " not to be found!";
    }

    return 0;
}