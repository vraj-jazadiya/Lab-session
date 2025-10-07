#include <iostream>

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

node* createNode(int val) {
    node* newNode = new node(val);
    return newNode;
}

int main() {
    node* head = createNode(10);


    if (head != NULL) {
        std::cout << "c++ : Node created with data = " << head->data << std::endl;
    }

    delete head;

    return 0;
}
