#include <iostream>
using namespace std;

int main()
{
    int m, n, i, j;

    cout << "enter rows: ";
    cin >> m;
    cout << "enter cols: ";
    cin >> n;

    int arr[m][n];
    int tr[n][m];

    cout << "\nenter x: \n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "enter for element at " << i << j << " : ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTranspose Matrix: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}