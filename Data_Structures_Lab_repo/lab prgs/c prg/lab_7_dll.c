#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *CreateNode(int x) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->prev=NULL;
    p->data = x;
    p->next = NULL;
    return p;
}
struct node * insertdllbeg(struct node *start, int x) {
    struct node *p = CreateNode(x);
    if(start==NULL){
        return p;
    }
    p->next = start;
    start->prev=p;
    start=p;
    return start;
}
struct node *deletespecelem(struct node *start,int x){
    struct node *temp;
    if(start==NULL){
        printf("linked list is empty");
    }
    else{
        temp=start;
        while(temp!=NULL && temp->data!=x){
            temp=temp->next; 
        }
        if(temp==NULL){
            printf("element not found");
        }
        else{
            if(temp->data==start->data){
                printf("deleted element is %d",temp->data);
                start=start->next;
                start->prev=NULL;
                free(temp);
                
            }
            else{
                printf("deleted element is %d",temp->data);
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
            }
        }
    }
    return start;
}

void displaydlllist(struct node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    printf("doubly Linked list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *start = NULL;
    int choice, val;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete specific element\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            start = insertdllbeg(start, val);
            break;

        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &val);
            start = deletespecelem(start, val);
            break;

        case 3:
            displaydlllist(start);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}