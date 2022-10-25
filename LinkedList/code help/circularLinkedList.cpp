#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data =data;
        this->next = NULL;
    }
    ~Node(){
        int value =this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory freed "<<value<<endl;
    }
};
void insertNode(Node* &t,int key,int data){
    //empty linkedlist 
    if(t==NULL){
        Node *newNode =new Node(data);
        t= newNode;
        newNode->next=newNode;
    }
    //non empty linkedlist
    else
    {
        Node* curr=t;
        while (curr->data!=key)
        {
            curr =curr->next;
        }
        Node *newNode =new Node(data);
        newNode->next =curr->next;
        curr->next = newNode;
    }
    
}
void print (Node* t){
    Node* temp=t;
    if (t==NULL)
    {
        cout<<endl<<"empty Linked List"<<endl;
    } 
    do
    {
        cout<<t->data<<"->";
        t=t->next;
    }while (t !=temp);
    cout<<endl;
}
void deleteNode(Node* &t,int value){
    if (t==NULL)
    {
        cout<<"the linked list is empty";
    }
    else
    {
        Node* prev=t;
        Node* curr=prev->next;
        while (curr->data !=value)
        {
            prev =curr;
            curr=curr->next;
        }
        if(curr==prev){
            t=NULL;
        }
        //
        prev->next =curr->next;
        if (t==curr)
        {
            t=prev;
        }
        curr->next =NULL;
        delete curr;
    }
    
}
int main(){
    Node* t =NULL;
    insertNode(t,5,3);
    print(t); 
    insertNode(t,3,5);
    print(t); 
    insertNode(t,5,8);
    print(t); 
    insertNode(t,3,888);
    print(t);   
    deleteNode(t,3);
    print(t);
    deleteNode(t,5);
    print(t);

}