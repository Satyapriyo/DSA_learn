#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void print(struct node* p){
    // if (p==NULL)    return;
    // printf("%d",p->data);
    // print(p->next);//recursive call
    struct node *temp = p;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
struct node* insert(node* head,int data){
    struct node *temp = new node();
    temp->data = data;
    temp ->next = NULL;
    if(head == NULL)    head =temp;
    else{
        node* temp1 =head;
        while(temp1!=NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}
int main(){
    struct node* head =NULL;
    head= insert(head,3);
    head= insert(head,6);
    head= insert(head,37);
    head= insert(head,9);
    head= insert(head,5);
    print(head);
}