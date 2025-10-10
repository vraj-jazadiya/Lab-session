// Create a new node
Node* createNode(int val);

// Insert at beginning
void insertAtBeginning(Node*& head, int val);

// Insert at end
void insertAtEnd(Node*& head, int val);

// Insert after a specific position
void insertAfterPosition(Node* head, int pos, int val);

// Delete from beginning 
void deleteFromBeginning(Node*& head);

// Delete from end
void deleteFromEnd(Node*& head);

// Delete specific node 
void deleteNode(Node*& head, int val);

// Search an element
int searchElement(Node* head, int val);

// Display the list
void displayList(Node* head);
