#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

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
        printf("9. Exit\n");
        printf("Enter your c: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("insertend: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("insert: ");
                scanf("%d", &value);
                printf("Enter pos: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6: {
                printf("delete: ");
                scanf("%d", &value);
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
                        printf("%d deleted\n", value);
                        deleted = true;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                if (!deleted) printf("%d not found\n", value);
                break;
            }
            case 7:
                printf("search: ");
                scanf("%d", &value);
                found = search(head, value);
                if (found) printf(" %d found\n", value);
                else printf(" %d not found\n", value);
                break;
            case 8:
                display(head);
                break;
            case 9:
                while (head != NULL) {
                    head = deleteFromBeginning(head);
                }
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid c\n");
        }
    }
}
