#include<stdio.h>
#define n 5
int queue[n];
int front=-1,rear=-1;
void insert(int x){
    if(rear==n-1){
        printf("queue overflow");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        int j=rear;
        while(j>=0 && queue[j]>x){
        queue[j+1]=queue[j];
        j--;
        }
    queue[j+1]=x;
    rear+=1;
    }
}

void delete(){
    if(front==-1||front>rear){
        printf("queue underflow");
    }
    else{
        printf("%d deleted",queue[front]);
        front++;
    }
}

void display(){
    if(front==-1||front>rear){
        printf("queue underflow");
    }
    else{
        printf("queue elements are:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}

void peek(){
    if(front==-1||front>rear){
        printf("queue underflow");
    }
    else {
        printf("%d is front element",queue[front]);
    }

  }


int main(){
    int choice,value;
    while(1){
        printf("\n menu\n1.insert\n2.delete\n3.display\n4.peek\n5.exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("enter value to insert");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("exit");
            return 0;
        default:
            printf("invalid choice");
    }

  }
}