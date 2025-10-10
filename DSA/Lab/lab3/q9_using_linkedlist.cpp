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
        while (temp->next != nullptr) {
            temp = temp->next;
        }
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
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Display List\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "insertend: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                list.deleteFromBeginning();
                break;
            case 4:
                list.deleteFromEnd();
                break;
            case 5:
                list.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
