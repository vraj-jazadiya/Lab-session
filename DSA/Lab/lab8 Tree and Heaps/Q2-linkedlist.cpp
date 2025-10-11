#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class bintree {
public:
    Node* root;

    bintree() {
        root = NULL;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        char choice;
        cout << "insert " << value << " to left or right of " << node->data << "? (l/r): ";
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
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(Node* node) {
        if (node == NULL) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int countTotal(Node* node) {
        if (node == NULL) return 0;
        return 1 + countTotal(node->left) + countTotal(node->right);
    }

    int countLeaf(Node* node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;
        return countLeaf(node->left) + countLeaf(node->right);
    }

    int countInternal(Node* node) {
        if (node == NULL || (node->left == NULL && node->right == NULL)) return 0;
        return 1 + countInternal(node->left) + countInternal(node->right);
    }
};

int main() {
    bintree tree;
    int n, value;

    cout << "node num: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "value: " << i + 1 << ": ";
        cin >> value;
        tree.insertNode(value);
    }

    cout << "\nIn-order Trvsl: ";
    tree.inorder(tree.root);

    cout << "\nPre-order Trvsl: ";
    tree.preorder(tree.root);

    cout << "\nPost-order Trvsl: ";
    tree.postorder(tree.root);

    cout << "\n\nHeight: " << tree.height(tree.root);
    cout << "\nTotal nodes: " << tree.countTotal(tree.root);
    cout << "\nInternal Nodes: " << tree.countInternal(tree.root);
    cout << "\nLeaf Nodes: " << tree.countLeaf(tree.root);

    cout << endl;

    return 0;
}
