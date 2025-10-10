#include <iostream>
using namespace std;

int main()
{
    int m, n, o, p;

    cout << "enter rows - first matrix : ";
    cin >> m;
    cout << "enter cols - first matrix : ";
    cin >> n;

    cout << "enter rows - second matrix : ";
    cin >> o;
    cout << "enter cols - second matrix : ";
    cin >> p;

    if (n == o)
    {
        cout << "\nMultiplication possible !!\n";
        int a[m][n], b[o][p], i, j, k, c[m][p];

        cout << "\n1st matrix \n";
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << "index " << i << j << " : ";
                cin >> a[i][j];
            }
        }

        cout << "\n2nd matrix \n";
        for (i = 0; i < o; i++)
        {
            for (j = 0; j < p; j++)
            {
                cout << "index " << i << j << " : ";
                cin >> b[i][j];
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

        for (i = 0; i < o; i++)
        {
            for (j = 0; j < p; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < p; j++)
            {
                c[i][j] = 0;
            }
        }

        cout << "\nMultition Array : \n";
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < p; j++)
            {
                for (k = 0; k < n; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < p; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nNo multiplication poassible !!!";
    }
    return 0;
}