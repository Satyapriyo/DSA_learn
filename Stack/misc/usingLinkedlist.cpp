#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* top=NULL;
void print(){
    if(top==NULL)
        return;
    struct node *temp =top;
    printf("\n");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp =temp->link;
    }
}
void push(int num){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->link =top;
    top = temp;
}
bool isEmpty(){
    if(top==NULL)   return true;
    else    return false;
}
void pop(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = top;
    top = temp->link;
    free(temp);
}
int main(){
    push(2);print();
    push(4);print();
    push(9);print();
    push(7);print();
    printf("\n");
    if(isEmpty())
        printf("the stack is empty and you have insert things to show");
    else
        printf("there is elements in stack");
    pop();
    print();
    pop();
    print();pop();
    print();
    return 0;
}
