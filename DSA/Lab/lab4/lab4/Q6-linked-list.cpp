#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    Node* createNode(int val) {
        return new Node(val);
    }

    void insertAtBeginning(int val) {
        Node* newNode = createNode(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = createNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Invalid position\n";
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        Node* newNode = createNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted from beginning\n";
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Deleted last node\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout << "Deleted from end\n";
    }

    void deleteNodeByValue(int val) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found\n";
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Deleted node with value " << val << "\n";
    }

    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int choice, val, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Node by Value\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Count Nodes\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                cout << "Enter position (0-based): ";
                cin >> pos;
                list.insertAtPosition(val, pos);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteNodeByValue(val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                if (list.search(val)) cout << "Found\n";
                else cout << "Not found\n";
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Total nodes: " << list.countNodes() << "\n";
                break;
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
