#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 50
int top=-1;
char stack[size];

void push(char c){
    if(top==size-1){
        printf("stack overload");
    }
    else{
        top+=1;
        stack[top]=c;
    }
}

char pop(){
    if(top==-1){
        printf("stack underflow");
        return -1;
    }
    else{
        int item=stack[top];
        top-=1;
        return item;
    }
}
int precedence(char c){
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/')return 2;
    if(c=='^')return 3;
    return 0;
}

void itf(char infix[],char postfix[]){
    int i,k=0;
    char c;
    for (i=0;infix[i]!='\0';i++){
        c=infix[i];
        if (isalnum(c)){
            postfix[k]=c;
            k+=1;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1&&stack[top]!='('){
                postfix[k]=pop();
                k+=1;
            }
            pop();
        }
        else{
            while(top!=-1&&precedence(stack[top])>=precedence(c)){
                postfix[k]=pop();
                k+=1;
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[k]=pop();
        k+=1;
    }
    postfix[k]='\0';
}
int main(){
    char infix[size],postfix[size];
    printf("Enter valid infix exp:\n");
    scanf("%s",infix);
    itf(infix,postfix);
    printf("Postfix exp is  %s\n",postfix);

}