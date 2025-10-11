#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Binarytree
{
public:
    node *root;

    Binarytree()
    {
        root = NULL;
    }

    void insert(int x)
    {
        node *newNode = new node(x);
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }

            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    void inorder(node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(node *node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void deleteNode(int x)
    {
        if (root == NULL)
        {
            cout << "tree is empty.\n";
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == x)
            {
                delete root;
                root = NULL;
                cout << "deleted.\n";
            }
            else
            {
                cout << "not found.\n";
            }
            return;
        }

        queue<node *> q;
        q.push(root);

        node *target = NULL;
        node *temp;
        node *last;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->data == x)
            {
                target = temp;
            }

            if (temp->left)
            {
                last = temp;
                q.push(temp->left);
            }

            if (temp->right)
            {
                last = temp;
                q.push(temp->right);
            }
        }

        if (target != NULL)
        {
            int deepestx = temp->data;
            deleteDeepest(root, temp);
            target->data = deepestx;
            cout << "node deleted.\n";
        }
        else
        {
            cout << "node not found.\n";
        }
    }

    void deleteDeepest(node *root, node *delNode)
    {
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                if (temp->left == delNode)
                {
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }
                else
                {
                    q.push(temp->left);
                }
            }

            if (temp->right)
            {
                if (temp->right == delNode)
                {
                    delete temp->right;
                    temp->right = NULL;
                    return;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
    }
};

int main()
{
    Binarytree tree;
    int choice, x;

    while (true)
    {
        cout << "1. Insert node\n";
        cout << "2. Delete node\n";
        cout << "3. In-order Traversal\n";
        cout << "4. Pre-order Traversal\n";
        cout << "5. Post-order Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "insert: ";
            cin >> x;
            tree.insert(x);
            break;
        case 2:
            cout << "delete: ";
            cin >> x;
            tree.deleteNode(x);
            break;
        case 3:
            cout << "In-order: ";
            tree.inorder(tree.root);
            cout << endl;
            break;
        case 4:
            cout << "Pre-order: ";
            tree.preorder(tree.root);
            cout << endl;
            break;
        case 5:
            cout << "Post-order: ";
            tree.postorder(tree.root);
            cout << endl;
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
