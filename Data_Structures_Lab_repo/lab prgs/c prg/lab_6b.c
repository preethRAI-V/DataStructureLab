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

struct node* push(struct node *top, int x) {
    struct node *temp = CreateNode(x);
    temp->next = top;
    top = temp;
    return top;
}


struct node* pop(struct node *top) {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return top;
    }
    struct node *temp = top;
    printf("Popped element = %d\n", top->data);
    top = top->next;
    free(temp);
    return top;
}

void displayStack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *t = top;
    printf("Stack (Top -> Bottom): ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

struct node* enqueue(struct node *front, struct node **rear, int x) {
    struct node *temp = CreateNode(x);
    if (front == NULL) {
        front = temp;
        *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
    return front;
}


struct node* dequeue(struct node *front, struct node **rear) {
    if (front == NULL) {
        printf("Queue underflow!\n");
        return front;
    }
    struct node *temp = front;
    printf("Dequeued element = %d\n", front->data);
    front = front->next;
    if (front == NULL)
        *rear = NULL;
    free(temp);
    return front;
}


void displayQueue(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *t = front;
    printf("Queue (Front -> Rear): ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}


int main() {

    struct node *stackTop = NULL;    
    struct node *queueFront = NULL;   
    struct node *queueRear = NULL;    

    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            stackTop = push(stackTop, val);
            break;

        case 2:
            stackTop = pop(stackTop);
            break;

        case 3:
            displayStack(stackTop);
            break;

        case 4:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            queueFront = enqueue(queueFront, &queueRear, val);
            break;

        case 5:
            queueFront = dequeue(queueFront, &queueRear);
            break;

        case 6:
            displayQueue(queueFront);
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice, try again!\n");
        }
    }
    
}
