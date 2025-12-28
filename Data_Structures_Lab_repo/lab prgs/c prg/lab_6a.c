#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *CreateNode(int x) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    return p;
}

struct node *insertAtEnd(struct node *start, int x) {
    struct node *temp = CreateNode(x);
    if (start == NULL) {
        return temp;
    }
    struct node *p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    return start;
}

struct node *sortsll(struct node *start) {
    struct node *temp, *p;
    int temp1;
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        temp = start;
        while (temp->next != NULL) {
            p = temp->next;
            while (p != NULL) {
                if (temp->data > p->data) {
                    temp1 = temp->data;
                    temp->data = p->data;
                    p->data = temp1;
                }
                p = p->next;
            }
            temp = temp->next;
        }
    }
    return start;
}

struct node *reversesll(struct node *start) {
    struct node *temp, *curr = NULL;
    while (start != NULL) {
        temp = start->next;
        start->next = curr;
        curr = start;
        start = temp;
    }
    return curr;
}

struct node *concat2sll(struct node *start, struct node *start1) {
    if (start == NULL || start1 == NULL) {
        printf("Cannot concatenate\n");
        return start;
    }
    struct node *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = start1;
    return start;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *p = start;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int choice, val;

   while(1){
        printf("\n--- MENU ---\n");
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Display List1\n");
        printf("4. Display List2\n");
        printf("5. Sort List1\n");
        printf("6. Reverse List1\n");
        printf("7. Concatenate List1 and List2\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                list1 = insertAtEnd(list1, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                list2 = insertAtEnd(list2, val);
                break;
            case 3:
                printf("List1: ");
                display(list1);
                break;
            case 4:
                printf("List2: ");
                display(list2);
                break;
            case 5:
                list1 = sortsll(list1);
                printf("List1 sorted.\n");
                break;
            case 6:
                list1 = reversesll(list1);
                printf("List1 reversed.\n");
                break;
            case 7:
                list1 = concat2sll(list1, list2);
                printf("Concatenated List1 + List2.\n");
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}