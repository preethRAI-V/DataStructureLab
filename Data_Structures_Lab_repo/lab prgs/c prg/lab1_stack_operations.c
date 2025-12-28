#include <stdio.h>
#define size 5
int top = -1;
int stack[size];

// PUSH
void push(int x) {
    if (top == size - 1) {
        printf("stack overflow\n");
    } else {
        top++;
        stack[top] = x;
        printf("%d pushed into stack\n", x);
    }
}

// POP
int pop() {
    if (top == -1) {
        printf("stack underflow\n");
        return -1;
    } else {
        int item = stack[top];
        top--;
        printf("%d popped\n", item);
        return item;
    }
}

// PEEK
void peek() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        printf("%d\n", stack[top]);
    }
}

// DISPLAY
void display() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        printf("stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n Menu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}
