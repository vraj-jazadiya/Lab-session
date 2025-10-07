#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

//Q1
Node* CreateNode(int value) {
    Node* newNode = new Node(value);
    return newNode;
}

//Q2
Node* InsertAtBeginning(Node* head, int value) {
    Node* newNode = CreateNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

//Q3
Node* InsertAtEnd(Node* head, int value) {
    Node* newNode = CreateNode(value);
    if (head == nullptr) return newNode;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//Q4
Node* InsertAtPosition(Node* head, int value, int pos) {
    if (pos == 0) return InsertAtBeginning(head, value);

    Node* newNode = CreateNode(value);
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == nullptr) {
            cout << "Invalid position\n";
            delete newNode;
            return head;
        }
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Invalid position\n";
        delete newNode;
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}


//Q5
Node* DeleteFromBeginning(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

//Q6
Node* DeleteFromEnd(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

//Q7
bool Search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

//Q8
void Display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    Node* head = nullptr;
    head = InsertAtBeginning(head, 10);
    head = InsertAtBeginning(head, 20);
    head = InsertAtEnd(head, 30);
    head = InsertAtPosition(head, 25, 2);
    Display(head);

    cout << "Search 20: " << (Search(head, 20) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (Search(head, 40) ? "Found" : "Not Found") << endl;

    head = DeleteFromBeginning(head);
    Display(head);

    head = DeleteFromEnd(head);
    Display(head);

    return 0;
}
