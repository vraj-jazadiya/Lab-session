#include <iostream>
using namespace std;

int main()
{
    int mat[2][2],i,j,det;

    for(i = 0;i < 2;i++)
    {
        for(j = 0;j < 2;j++)
        {
            cout<<"enter for ele at "<<i<<j<<" : ";cin>>mat[i][j];
        }
        cout<<endl;
    }

    for(i = 0;i < 2;i++)
    {
        for(j = 0;j < 2;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    cout<<"\n determinant = "<<det;
    return 0;
}