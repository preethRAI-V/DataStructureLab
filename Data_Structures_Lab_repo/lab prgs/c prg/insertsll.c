#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *CreateNode(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}


void insertsllbeg(struct node **start, int x) {
    struct node *newNode = CreateNode(x);
    newNode->next = *start;
    *start = newNode;
}


void insertsllend(struct node **start, int x) {
    struct node *newNode = CreateNode(x);
    if (*start == NULL) {
        *start = newNode;
        return;
    }
    struct node *temp = *start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtPosition(struct node **start, int x, int position) {
    struct node *newNode = CreateNode(x);

    if (position == 1) {
        newNode->next = *start;
        *start = newNode;
        return;
    }

    struct node *temp = *start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayslllist(struct node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *start = NULL;
    int choice, value, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertsllbeg(&start, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertsllend(&start, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&start, value, position);
                break;
            case 4:
                displayslllist(start);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

}