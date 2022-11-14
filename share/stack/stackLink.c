#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* top=NULL;
int isEmpty(){
    if(top==NULL)   return 1;
    else    return 0;
}
void print(){
    if(isEmpty())
        printf("the stack is empty and you have insert things to show");
    else
        printf("there is elements in stack");
    if(top==NULL)
        return;
    struct node *temp =top;
    printf("\n");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp =temp->link;
    }
}
void push(){
    int num;
    printf("enter data \n");
    scanf("%d",&num);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->link =top;
    top = temp;
}

void pop(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = top;
    top = temp->link;
    free(temp);
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
