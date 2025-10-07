#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        char choice;
        cout << "Insert " << value << " to left or right of " << node->data << "? (l/r): ";
        cin >> choice;
        if (choice == 'l') {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insertNode(int value) {
        root = insert(root, value);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void mirror(Node* node) {
        if (node == nullptr) return;
        mirror(node->left);
        mirror(node->right);

        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        tree.insertNode(value);
    }

    cout << "\nInorder before mirror: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.mirror(tree.root);

    cout << "Inorder after mirror: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
