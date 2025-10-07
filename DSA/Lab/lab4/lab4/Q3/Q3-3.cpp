// Algorithm 3: Insert at End
// Algorithm InsertAtEnd(head, value)
// 1. Create newNode using CreateNode(value)
// 2. If head is NULL:
//  a. Return newNode
// 3. Set temp ← head
// 4. While temp→next ≠ NULL:
//  a. temp ← temp→next
// 5. temp→next ← newNode
// 6. Return head

#include <iostream>

class node
{
public:
    int data;
    node *next;

    node(int vlu)
    {
        data = vlu;
        next = NULL;
    }
};

node *createNode(int vlu)
{
    return new node(vlu);
}

node *insertEnd(node *head, int value)
{
    node *newNode = createNode(value);
    if (!newNode)
        return head;

    if (head == NULL)
    {
        return newNode;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void displayList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main()
{
    node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    displayList(head);

    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
