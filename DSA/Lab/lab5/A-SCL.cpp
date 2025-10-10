#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class SinglyCircularList {
    Node* last;

public:
    SinglyCircularList() : last(NULL) {}

    ~SinglyCircularList() {
        if (!last) return;
        Node* curr = last->next;
        last->next = NULL; 
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void deleteNode(int val) {
        if (!last) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = last->next;
        Node* prev = last;
        bool found = false;

        do {
            if (curr->data == val) {
                found = true;

                if (curr == prev) {
                    delete curr;
                    last = NULL;
                } else {
                    prev->next = curr->next;
                    if (curr == last) {
                        last = prev;
                    }
                    delete curr;
                }

                cout << "Deleted: " << val << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        if (!found) {
            cout << val << " not found \n";
        }
    }

    void display() const {
        if (!last) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = last->next;
        cout << "List contents: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    SinglyCircularList scl;
    int choice, val;
    do {
        cout << "\nSingly Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter: ";
                cin >> val;
                scl.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter: ";
                cin >> val;
                scl.insertAtEnd(val);
                break;
            case 3:
                cout << "delete: ";
                cin >> val;
                scl.deleteNode(val);
                break;
            case 4:
                scl.display();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
