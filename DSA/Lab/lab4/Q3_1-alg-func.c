#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Algorithm 1: Create Node
struct Node* CreateNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Algorithm 2: Insert at Beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = CreateNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

// Algorithm 3: Insert at End
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = CreateNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Algorithm 4: Insert at Position (0-based index)
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos == 0) {
        return insertAtBeginning(head, value);
    }
    struct Node* newNode = CreateNode(value);
    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Algorithm 5: Delete from Beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Algorithm 6: Delete from End
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Algorithm 7: Search Element
bool search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Algorithm 8: Display List
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
