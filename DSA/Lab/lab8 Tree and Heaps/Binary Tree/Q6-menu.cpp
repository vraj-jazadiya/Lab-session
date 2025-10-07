#include <iostream>
#include <queue>
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

    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
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

    void deleteNode(int value) {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (root->data == value) {
                delete root;
                root = nullptr;
                cout << "Node deleted.\n";
            } else {
                cout << "Node not found.\n";
            }
            return;
        }

        queue<Node*> q;
        q.push(root);

        Node* target = nullptr;
        Node* temp;
        Node* last;

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->data == value) {
                target = temp;
            }

            if (temp->left) {
                last = temp;
                q.push(temp->left);
            }

            if (temp->right) {
                last = temp;
                q.push(temp->right);
            }
        }

        if (target != nullptr) {
            int deepestValue = temp->data;
            deleteDeepest(root, temp);
            target->data = deepestValue;
            cout << "Node deleted.\n";
        } else {
            cout << "Node not found.\n";
        }
    }

    void deleteDeepest(Node* root, Node* delNode) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left) {
                if (temp->left == delNode) {
                    delete temp->left;
                    temp->left = nullptr;
                    return;
                } else {
                    q.push(temp->left);
                }
            }

            if (temp->right) {
                if (temp->right == delNode) {
                    delete temp->right;
                    temp->right = nullptr;
                    return;
                } else {
                    q.push(temp->right);
                }
            }
        }
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. In-order Traversal\n";
        cout << "4. Pre-order Traversal\n";
        cout << "5. Post-order Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
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
