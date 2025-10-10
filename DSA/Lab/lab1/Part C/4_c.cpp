#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {10,20,30,40,50};
    int x,i,flag = 0;

    cout<<"find x ? : ";
    cin>>x;

    for(i = 0;i < 10;i++)
    {
        if (x == arr[i])
        {
            cout<<"element " << x << " found at index " << i << endl;
            flag++;
        }
    }

    if(!flag)
    {
        cout<<"X not found.";
    }

    return 0;
}