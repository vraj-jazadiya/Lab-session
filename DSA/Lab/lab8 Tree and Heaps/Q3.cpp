#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    Node *insert(Node *node, int x)
    {
        if (node == NULL)
        {
            return new Node(x);
        }
        char choice;
        cout << "insert " << x << " to left or right of " << node->data << "? (l/r): ";
        cin >> choice;
        if (choice == 'l')
        {
            node->left = insert(node->left, x);
        }
        else
        {
            node->right = insert(node->right, x);
        }
        return node;
    }

    void insertNode(int x)
    {
        root = insert(root, x);
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void mirror(Node *node)
    {
        if (node == NULL)
            return;
        mirror(node->left);
        mirror(node->right);

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

int main()
{
    BinaryTree tree;
    int n, x;

    cout << "node num: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "enter x " << i + 1 << ": ";
        cin >> x;
        tree.insertNode(x);
    }

    cout << "\nIn-order before mirror: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.mirror(tree.root);

    cout << "In-order after mirror: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
