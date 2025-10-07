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

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int countTotal(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countTotal(node->left) + countTotal(node->right);
    }

    int countLeaf(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return countLeaf(node->left) + countLeaf(node->right);
    }

    int countInternal(Node* node) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) return 0;
        return 1 + countInternal(node->left) + countInternal(node->right);
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

    cout << "\nIn-order Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPre-order Traversal: ";
    tree.preorder(tree.root);

    cout << "\nPost-order Traversal: ";
    tree.postorder(tree.root);

    cout << "\n\nHeight of Tree: " << tree.height(tree.root);
    cout << "\nTotal Nodes: " << tree.countTotal(tree.root);
    cout << "\nInternal Nodes: " << tree.countInternal(tree.root);
    cout << "\nLeaf Nodes: " << tree.countLeaf(tree.root);

    cout << endl;

    return 0;
}
