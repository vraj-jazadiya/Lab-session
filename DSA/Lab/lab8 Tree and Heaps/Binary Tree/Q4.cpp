#include <iostream>
using namespace std;

class BinaryTreeArray {
    int tree[100];
    int size;

public:
    BinaryTreeArray() {
        size = 0;
        for (int i = 0; i < 100; i++) {
            tree[i] = -1;
        }
    }

    void insert(int value) {
        if (size < 100) {
            tree[size] = value;
            size++;
        } else {
            cout << "Tree is full\n";
        }
    }

    void levelOrder() {
        cout << "Level-order Traversal: ";
        for (int i = 0; i < size; i++) {
            if (tree[i] != -1)
                cout << tree[i] << " ";
        }
        cout << endl;
    }

    void displayArray() {
        cout << "Tree Array: ";
        for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTreeArray bt;
    int n, value;

    cout << "Enter number of xs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        bt.insert(value);
    }

    bt.displayArray();
    bt.levelOrder();

    return 0;
}
