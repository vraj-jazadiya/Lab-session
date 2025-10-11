#include <iostream>
using namespace std;

class binTreeArr
{
    int tree[100];
    int size;

public:
    binTreeArr()
    {
        for (int i = 0; i < 100; i++)
        {
            tree[i] = -1;
        }
        size = 0;
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

    void displayArray()
    {
        cout << "tree as array: ";
        for (int i = 0; i < size; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    void inorder(int i)
    {
        if (i >= size || tree[i] == -1)
            return;
        inorder(2 * i + 1);
        cout << tree[i] << " ";
        inorder(2 * i + 2);
    }

    void preorder(int i)
    {
        if (i >= size || tree[i] == -1)
            return;
        cout << tree[i] << " ";
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }

    void postorder(int i)
    {
        if (i >= size || tree[i] == -1)
            return;
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        cout << tree[i] << " ";
    }
};

int main()
{
    binTreeArr bt;
    int n, x;

    cout << "enter size: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "enter x " << i + 1 << ": ";
        cin >> x;
        bt.insert(x);
    }

    bt.displayArray();

    cout << "In-order travsl: ";
    bt.inorder(0);
    cout << endl;

    cout << "Pre-order travsl: ";
    bt.preorder(0);
    cout << endl;

    cout << "Post-order travsl: ";
    bt.postorder(0);
    cout << endl;

    return 0;
}
