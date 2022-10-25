#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node* next ;
};
struct node* head;
void insert(int data, int pos){
    node* temp1=new node();
    temp1-> data = data;
    temp1->next =NULL;
    if(pos==1){
        temp1->next =head;
        head = temp1;
        return;
    }
    node * temp2 =head;
    for (int i = 0; i < pos-2; i++)//this will point to n-1th node
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void print (){
    node* temp =head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
        head = NULL;//empty list
        insert(2,1);//list: 2    
        insert(3,2);//list: 2 3    
        insert(4,1);//list: 4 2 3
        insert(5,2);//list: 4 5 2 3  
        print();  //out put should be  4 5 2 3
}
