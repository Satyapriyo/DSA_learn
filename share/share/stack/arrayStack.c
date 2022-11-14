#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3
int a[MAX_SIZE];
int top = -1;
int isFull(){
    if(top==MAX_SIZE-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(){
    int num;
    if(isFull()){
        printf("Error stack overflow\n");
        return;
    }
    else {
        printf("enter the data\n");
        scanf("%d",&num);
        a[++top]=num;
    }
}
void pop(){
    if(isEmpty())
        printf("underflow\n");
    else
        top--;
}
void print(){
    int i;
    printf("stack :");
    for (int i = top; i>=0; i--)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int ch;
    printf("enter 1 to push\n");
    printf("enter 2 to pop\n");
    printf("enter 3 print\n");
    printf("enter 4 exit\n");
    while(1){
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
        }
    }   
    return 0;
}
