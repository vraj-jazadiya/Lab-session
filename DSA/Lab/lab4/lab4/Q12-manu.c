#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* createDNode(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct DNode* insertAtBeginning(struct DNode* head, int value) {
    struct DNode* newNode = createDNode(value);
    if (newNode == NULL) return head;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) head->prev = newNode;
    head = newNode;
    return head;
}

struct DNode* insertAtEnd(struct DNode* head, int value) {
    struct DNode* newNode = createDNode(value);
    if (newNode == NULL) return head;
    if (head == NULL) return newNode;
    struct DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct DNode* insertAtPosition(struct DNode* head, int value, int pos) {
    if (pos == 0) return insertAtBeginning(head, value);
    struct DNode* newNode = createDNode(value);
    if (newNode == NULL) return head;
    struct DNode* temp = head;
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
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct DNode* deleteFromBeginning(struct DNode* head) {
    if (head == NULL) return NULL;
    struct DNode* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

struct DNode* deleteFromEnd(struct DNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct DNode* deleteAtPosition(struct DNode* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 0) return deleteFromBeginning(head);
    struct DNode* temp = head;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}

bool search(struct DNode* head, int key) {
    struct DNode* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void displayForward(struct DNode* head) {
    struct DNode* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(struct DNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("List backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct DNode* head = NULL;
    int choice, value, pos;
    bool found;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Node (by position)\n");
        printf("7. Search an Element\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0-based): ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                printf("Deleted from beginning if list was not empty.\n");
                break;
            case 5:
                head = deleteFromEnd(head);
                printf("Deleted from end if list was not empty.\n");
                break;
            case 6:
                printf("Enter position of node to delete (0-based): ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                printf("Deleted node at position %d if valid.\n", pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = search(head, value);
                if (found)
                    printf("Value %d found in list.\n", value);
                else
                    printf("Value %d not found.\n", value);
                break;
            case 8:
                displayForward(head);
                break;
            case 9:
                displayBackward(head);
                break;
            case 10:
                while (head != NULL) {
                    head = deleteFromBeginning(head);
                }
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
