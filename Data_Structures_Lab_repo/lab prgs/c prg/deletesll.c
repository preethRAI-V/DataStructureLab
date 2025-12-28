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

struct node *deleteelemfirst(struct node *start){
    struct node *temp;
    if(start==NULL){
        printf("linked list is empty");
    }
    else if(start->next==NULL){
        printf("deleted element is %d",start->data);
        temp=start;
        start=NULL;
        free(temp);
        return NULL;
    }
    else{
        printf("%d deleted",start->data);
        temp=start;
        start=start->next;
        free(temp);
    }
    return start;
};
struct node *deleteelemlast(struct node *start){
    struct node *temp,*follow;
    if(start==NULL){
        printf("linked list is empty");
    }
    else if(start->next==NULL){
        printf("deleted element is %d",start->data);
        temp=start;
        start=NULL;
        free(temp);
        return NULL;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            follow=temp;
            temp=temp->next;
        }
        printf("deleted element is %d",temp->data);
        follow->next=NULL;
        free(temp);

    }
    return start;
};
struct node *deleteelemspecelem(struct node *start,int x){
    struct node *temp,*follow;
    if(start==NULL){
        printf("linked list is empty");
    }
    else{
        temp=start;
        while(temp!=NULL && temp->data!=x){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("element not found");
        }
        else{
            if(temp->data==start->data){
                printf("deleted element is %d",temp->data);
                start=start->next;
                free(temp);
            }
            else{
                printf("deleted element is %d",temp->data);
                follow->next=temp->next;
                free(temp);
            }
        }
        return start;
    }
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
    int choice, val;

    while(1){
        printf("\n--- MENU ---\n");
        printf("1. Insert element at end\n");
        printf("2. Delete first element\n");
        printf("3. Delete last element\n");
        printf("4. Delete specific element\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            start = insertAtEnd(start, val);
            break;
        case 2:
            start = deleteelemfirst(start);
            break;
        case 3:
            start = deleteelemlast(start);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            start = deleteelemspecelem(start, val);
            break;
        case 5:
            displayslllist(start);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}