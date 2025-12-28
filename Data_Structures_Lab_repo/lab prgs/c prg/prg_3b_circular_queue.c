#include<stdio.h>
#define n 5
int queue[n];
int front=-1,rear=-1;
void insert(int x){
    if(((rear+1)%n)==front){
        printf("queue overflow");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
    rear=(rear+1)%n;
    queue[rear]=x;
    printf("%d inserted\n",x);
    }
}

void delete(){
    if(front==-1){
        printf("queue underflow");
    }
    else{
        printf("%d deleted",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%n;
        }
    }
}

void display(){
    if(front==-1){
        printf("queue underflow");
    }
    else{
        printf("queue elements are:\n");
        int i=front;
        while(i!=rear){
            printf("%d\n",queue[i]);
            i=(i+1)%n;
        }
        printf("%d",queue[rear]);
        }
}


int main(){
    int choice,value;
    while(1){
        printf("\n menu\n1.insert\n2.delete\n3.display\n4.exit\n");
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
            printf("exit");
            return 0;
        default:
            printf("invalid choice");
    }

  }
}