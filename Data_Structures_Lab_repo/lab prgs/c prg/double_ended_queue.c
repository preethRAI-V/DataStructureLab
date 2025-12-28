#include <stdio.h>
#define n 5
int q[n];
int front = -1 , rear = -1 ;

void insert_front(int x) {
    if (rear == n - 1) {
        printf("queue overflow\n");
    }
    else if (front == -1) {
        front = rear = 0;
        q[front] = x;
        printf("%d inserted into queue\n", q[front]);
    }
    else {
        for (int i = rear; i >= front; i--) {
            q[i+1] = q[i];
        }
        q[front] = x;
        rear++;
    }
}

void delete_front() {
    if (front == -1) {
        printf("queue underflow\n");
    }
    else {
        int val = q[front];
        for (int i = front; i < rear; i++) {
            q[i] = q[i+1];
        }
        rear--;
        printf("%d deleted from front\n", val);
    }
}

void insert_rear(int x) {
    if (rear == n - 1) {
        printf("queue overflow\n");
    }
    else if (front == -1) {
        front = rear = 0;
        q[rear] = x;
        printf("%d inserted into queue\n", q[front]);
    }
    else {
        rear++;
        q[rear] = x;
        printf("%d inserted into queue\n", q[rear]);
    }
}

void delete_rear() {
    if (front == -1) {
        printf("queue underflow\n");
    }
    else {
        printf("%d deleted element\n", q[rear]);
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("queue underflow\n");
    }
    else {
        printf("queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", q[i]);
        }
    }
}

int main() {
    int choice , value ;
    while (1) {

        printf("\n menu\n 1. insert_front \n 2. delete_front\n 3. insert_rear\n 4. delete_rear\n 5. display\n 6. exit\n");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("enter value to insert: ");
                scanf("%d", &value);
                insert_front(value);
                break;

            case 2:
                delete_front();
                break;

            case 3:
                printf("enter value to insert: ");
                scanf("%d", &value);
                insert_rear(value);
                break;

            case 4:
                delete_rear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}
