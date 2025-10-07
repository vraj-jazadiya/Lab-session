class DoublyLinkedList {
public:
    Node* createNode(int value);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAfterPosition(int value, int pos);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteNode(int value);
    bool search(int key);
    void displayForward();
    void displayBackward();
};
