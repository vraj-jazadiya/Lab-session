#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int prn;
    char name[50];
    char phone[15];
    char city[30];
    float hscMarks;
    struct Student* next;
};

struct Student* head = NULL;

struct Student* createNode() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("Memory alloc failed\n");
        exit(1);
    }
    printf("Enter PRN: ");
    scanf("%d", &newNode->prn);

    printf("Enter Name: ");
    fgets(newNode->name, sizeof(newNode->name), stdin);
    newNode->name[strcspn(newNode->name, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(newNode->phone, sizeof(newNode->phone), stdin);
    newNode->phone[strcspn(newNode->phone, "\n")] = '\0';

    printf("Enter City: ");
    fgets(newNode->city, sizeof(newNode->city), stdin);
    newNode->city[strcspn(newNode->city, "\n")] = '\0';

    printf("Enter HSC Marks: ");
    scanf("%f", &newNode->hscMarks);

    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning() {
    struct Student* newNode = createNode();
    newNode->next = head;
    head = newNode;
}

void insertAtEnd() {
    struct Student* newNode = createNode();
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Student* temp = head;
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
        printf("Deleted last record.\n");
        return;
    }
    struct Student* temp = head;
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
    struct Student* temp = head;
    printf("Student Records:\n");
    while (temp != NULL) {
        printf("PRN: %d\n", temp->prn);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("City: %s\n", temp->city);
        printf("HSC Marks: %.2f\n\n", temp->hscMarks);
        temp = temp->next;
    }
}

int count() {
    int cnt = 0;
    struct Student* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void searchByPRN(int prn) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->prn == prn) {
            printf("Record Found:\n");
            printf("PRN: %d\n", temp->prn);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("City: %s\n", temp->city);
            printf("HSC Marks: %.2f\n", temp->hscMarks);
            return;
        }
        temp = temp->next;
    }
    printf("Record with PRN %d not found.\n", prn);
}

int main() {
    int choice, prn;
    while (1) {
        printf("\nStudent Record Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n");
        printf("5. Display all Records\n6. Count Records\n7. Search by PRN\n8. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
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
                printf("Total records: %d\n", count());
                break;
            case 7:
                printf("Enter PRN to search: ");
                scanf("%d", &prn);
                getchar();
                searchByPRN(prn);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
