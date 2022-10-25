#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node* next;
};
void print(node* head){
    while(head!= NULL){
        cout<<head -> data<<" ";
        head=head->next;
    }
}
struct node *insert(node *head,int data){
    node *temp =new node();
    temp->data=data;
    temp->next=NULL;
    // head =temp;
    // return head;
    //inserting from starting of the linked list
    if(head==NULL)  head = temp;
    else{
        node* temp1= head;
        while (temp1 !=NULL)    temp1 = temp1->next;
        temp1->next=temp;
    }
    return head;
}
struct node *reversed(node* head){
    node *temp,*prev,*current,*next;
    current=head;
    prev = NULL;
    while(temp!=NULL){
        next = current->next;//storing the link of next element before making change
        current->next = prev;//fixing the previos link
        prev = current;// prev is currnt looping icrement over here
        current = next;//making current to next
    }
    head = prev;
    return head;
}
int main(){
    struct node* head=NULL;
    head=insert(head,2);
    head=insert(head,1);
    head=insert(head,9);
    head=insert(head,6);
    head=insert(head,5);
    print(head);
    head = reversed(head);
    print(head);
    return 0;
}