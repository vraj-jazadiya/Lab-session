#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
                printf("enter pos: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                printf("Deleted from beginning \n");
                break;
            case 5:
                head = deleteFromEnd(head);
                printf("Deleted from end \n");
                break;
            case 6:
                printf("Enter pos for delte ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                printf("Deleted node pos %d \n", pos);
                break;
            case 7:
                printf("search: ");
                scanf("%d", &value);
                found = search(head, value);
                if (found)
                    printf("%d found\n", value);
                else
                    printf("%d not found.\n", value);
                break;
            case 8:
                printf("forward: ");
                displayForward(head);
                break;
            case 9:
                printf("backward: ");
                displayBackward(head);
                break;
            case 10:
                while (head != NULL) {
                    head = deleteFromBeginning(head);
                }
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
