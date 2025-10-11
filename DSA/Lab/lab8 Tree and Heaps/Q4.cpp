#include <iostream>
using namespace std;

class binTreeArr
{
    int tree[100];
    int size;

public:
    binTreeArr()
    {
        size = 0;
        for (int i = 0; i < 100; i++)
        {
            tree[i] = -1;
        }
    }

    void insert(int x)
    {
        if (size < 100)
        {
            tree[size] = x;
            size++;
        }
        else
        {
            cout << "tree is full\n";
        }
    }

    void levelOrder()
    {
        cout << "level-order traversal: ";
        for (int i = 0; i < size; i++)
        { 
            if (tree[i] != -1)
                cout << tree[i] << " ";
        }
        cout << endl;
    }

    void displayArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    binTreeArr bt;
    int n, x;

    cout << "size: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "value: " << i + 1 << ": ";
        cin >> x;
        bt.insert(x);
    }

    bt.displayArray();
    bt.levelOrder();

    return 0;
}
