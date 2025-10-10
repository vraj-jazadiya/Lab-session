#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
};

struct DNode *createDNode(int value)
{
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct DNode *insertAtBeginning(struct DNode *head, int value)
{
    struct DNode *newNode = createDNode(value);
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    return head;
}

struct DNode *insertAtEnd(struct DNode *head, int value)
{
    struct DNode *newNode = createDNode(value);
    if (head == NULL)
        return newNode;
    struct DNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct DNode *insertAtPosition(struct DNode *head, int value, int pos)
{
    if (pos == 0)
        return insertAtBeginning(head, value);
    struct DNode *newNode = createDNode(value);
    struct DNode *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct DNode *deleteFromBeginning(struct DNode *head)
{
    if (head == NULL)
        return NULL;
    struct DNode *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

struct DNode *deleteFromEnd(struct DNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct DNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct DNode *deleteAtPosition(struct DNode *head, int pos)
{
    if (head == NULL)
        return NULL;
    if (pos == 0)
        return deleteFromBeginning(head);
    struct DNode *temp = head;
    for (int i = 0; i < pos; i++)
    {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}

bool search(struct DNode *head, int key)
{
    struct DNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void displayForward(struct DNode *head)
{
    struct DNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(struct DNode *head)
{
    if (head == NULL)
        return;
    struct DNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
