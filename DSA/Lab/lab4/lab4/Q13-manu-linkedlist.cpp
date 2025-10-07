#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        DNode* newNode = new DNode(value);
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        DNode* newNode = new DNode(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int pos) {
        if (pos == 0) {
            insertAtBeginning(value);
            return;
        }
        DNode* newNode = new DNode(value);
        DNode* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Invalid position\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        DNode* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
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
        DNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }
        DNode* temp = head;
        for (int i = 0; i < pos; i++) {
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
        temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int key) {
        DNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        DNode* temp = head;
        cout << "List forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        cout << "List backward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    ~DoublyLinkedList() {
        while (head != nullptr)
            deleteFromBeginning();
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search an Element\n";
        cout << "8. Display Forward\n";
        cout << "9. Display Backward\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (0-based): ";
                cin >> pos;
                dll.insertAtPosition(value, pos);
                break;
            case 4:
                dll.deleteFromBeginning();
                break;
            case 5:
                dll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete (0-based): ";
                cin >> pos;
                dll.deleteAtPosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                if (dll.search(value))
                    cout << "Value found\n";
                else
                    cout << "Value not found\n";
                break;
            case 8:
                dll.displayForward();
                break;
            case 9:
                dll.displayBackward();
                break;
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
