#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createDNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning_DLL(struct Node* head, int value) {
    struct Node* newNode = createDNode(value);
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    return head;
}

struct Node* insertAtEnd_DLL(struct Node* head, int value) {
    struct Node* newNode = createDNode(value);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* insertAtPosition_DLL(struct Node* head, int value, int pos) {
    if (pos == 0)
        return insertAtBeginning_DLL(head, value);
    struct Node* newNode = createDNode(value);
    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
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

struct Node* deleteFromBeginning_DLL(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteFromEnd_DLL(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtPosition_DLL(struct Node* head, int pos) {
    if (head == NULL)
        return NULL;
    if (pos == 0)
        return deleteFromBeginning_DLL(head);
    struct Node* temp = head;
    for (int i = 0; i < pos; i++) {
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

bool search_DLL(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void displayForward_DLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward_DLL(struct Node* head) {
    if (head == NULL)
        return;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
