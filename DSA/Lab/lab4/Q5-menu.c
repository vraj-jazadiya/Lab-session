#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* creatNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allc faild\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = creatNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = creatNode(value);
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

struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos == 0) {
        return insertAtBeginning(head, value);
    }
    struct Node* newNode = creatNode(value);
    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid positon\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid positon\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
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

bool search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* deleteNodeByValue(struct Node* head, int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    bool deleted = false;
    while (temp != NULL) {
        if (temp->data == value) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf(" %d deleted\n", value);
            deleted = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!deleted) printf("%d not found\n", value);
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int c, value, pos;
    bool found;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Node (by value)\n");
        printf("7. Search an Element\n");
        printf("8. Display List\n");
        printf("9. Count Nodes\n");
        printf("10. Exit\n");
        printf("Enter yr c: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("insert: ");
                scanf("%d", &value);
                printf("Enter position (0-based): ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("delete: ");
                scanf("%d", &value);
                head = deleteNodeByValue(head, value);
                break;
            case 7:
                printf("search: ");
                scanf("%d", &value);
                found = search(head, value);
                if (found) printf("%d found\n", value);
                else printf("%d not found\n", value);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Total nodes = %d\n", countNodes(head));
                break;
            case 10:
                while (head != NULL) {
                    head = deleteFromBeginning(head);
                }
                printf("Exiting \n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
