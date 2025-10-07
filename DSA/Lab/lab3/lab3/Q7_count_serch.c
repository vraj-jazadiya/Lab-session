#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int val);
void insertAtEnd(int val);
void deleteFromBeginning();
void deleteFromEnd();
void display();
int countNodes();
int searchNode(int val);

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Count Nodes\n");
        printf("7. Search Node\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (searchNode(value))
                    printf("%d found in the list.\n", value);
                else
                    printf("%d not found in the list.\n", value);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void insertAtBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted from beginning.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Deleted from end.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchNode(int val) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}
