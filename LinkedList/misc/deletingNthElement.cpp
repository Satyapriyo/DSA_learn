#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node* next;
};
struct node* head;//struct node is important not only node
void insert(int element){
    node* temp= new node();
    temp->data = element;
    temp->next = head;
    head = temp;
}
void print(){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void delet(int pos){
    node *temp1 =head;
    if(pos ==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < pos-2; i++)//after this for loop executed temp will store the address of n-1th term
        temp1 =temp1->next;
    node *temp2=temp1->next;// this line temp2 is storing nth address
    temp1->next = temp2->next; //temp1 is storing n+1th terms address
    free(temp2);
}
int main(){
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    delet(1);list :// 2 3 5
    print();
    return 0;
}