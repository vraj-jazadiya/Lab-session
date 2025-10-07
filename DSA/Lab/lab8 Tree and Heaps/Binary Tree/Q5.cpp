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

    void displayArray() {
        cout << "Tree Array: ";
        for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    bool isComplete() {
        for (int i = 0; i < size; i++) {
            if (tree[i] == -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    BinaryTreeArray bt;
    int n, value;

    cout << "Enter number of xs to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value at position " << i << ": ";
        cin >> value;
        bt.insert(value);
    }

    bt.displayArray();

    if (bt.isComplete()) {
        cout << "The binary tree is a Complete Binary Tree." << endl;
    } else {
        cout << "The binary tree is NOT a Complete Binary Tree." << endl;
    }

    return 0;
}
