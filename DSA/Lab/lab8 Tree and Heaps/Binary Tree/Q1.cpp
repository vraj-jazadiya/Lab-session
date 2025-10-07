#include <iostream>
using namespace std;

class BinaryTreeArray {
    int tree[100];
    int size;

public:
    BinaryTreeArray() {
        for (int i = 0; i < 100; i++) {
            tree[i] = -1;
        }
        size = 0;
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
        cout << "Tree as array: ";
        for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    void inorder(int index) {
        if (index >= size || tree[index] == -1)
            return;
        inorder(2 * index + 1);
        cout << tree[index] << " ";
        inorder(2 * index + 2);
    }

    void preorder(int index) {
        if (index >= size || tree[index] == -1)
            return;
        cout << tree[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void postorder(int index) {
        if (index >= size || tree[index] == -1)
            return;
        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << tree[index] << " ";
    }
};

int main() {
    BinaryTreeArray bt;
    int n, value;

    cout << "Enter number of xs to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        bt.insert(value);
    }

    bt.displayArray();

    cout << "Inorder traversal: ";
    bt.inorder(0);
    cout << endl;

    cout << "Preorder traversal: ";
    bt.preorder(0);
    cout << endl;

    cout << "Postorder traversal: ";
    bt.postorder(0);
    cout << endl;

    return 0;
}
