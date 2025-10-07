// Algorithm 2: Insert at Beginning
// Algorithm InsertAtBeginning(head, value)
// 1. Create newNode using CreateNode(value)
// 2. Set newNode→next ← head
// 3. Set head ← newNode
// 4. Return head

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

node *insertBegining(node *head, int vlu)
{
    node *newNode = createNode(vlu);
    if (!newNode)
        return head;

    newNode->next = head;
    head = newNode;
    return head;
}

void displayList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << "->";
        temp = temp->next;
    }

    std::cout << "NULL \n";
}

int main()
{
    node *head = NULL;

    head = insertBegining(head, 10);
    head = insertBegining(head, 20);
    head = insertBegining(head, 30);

    displayList(head);

    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}