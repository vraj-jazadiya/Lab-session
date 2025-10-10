#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyCircularList {
    DNode* head;

public:
    DoublyCircularList() : head(NULL) {}

    ~DoublyCircularList() {
        if (!head) return;
        DNode* curr = head->next;
        while (curr != head) {
            DNode* next = curr->next;
            delete curr;
            curr = next;
        }
        delete head;
    }

    void insertEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
        } else {
            DNode* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
        }
    }

    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        DNode* curr = head;
        DNode* toDelete = NULL;

        do {
            if (curr->data == val) {
                toDelete = curr;
                break;
            }
            curr = curr->next;
        } while (curr != head);

        if (!toDelete) {
            cout << "Value " << val << " not found\n";
            return;
        }

        if (toDelete->next == toDelete) {
            head = NULL;
        } else {
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            if (toDelete == head) {
                head = toDelete->next;
            }
        }

        delete toDelete;
        cout << "Deleted " << val << endl;
    }

    void display() const {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        DNode* temp = head;
        cout << "List contents: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularList dcl;
    int choice, val;

    do {
        cout << "\nDoubly Circular Linked List Menu ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete Node\n";
        cout << "3. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "insert: ";
                cin >> val;
                dcl.insertEnd(val);
                break;
            case 2:
                cout << "delete: ";
                cin >> val;
                dcl.deleteNode(val);
                break;
            case 3:
                dcl.display();
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
