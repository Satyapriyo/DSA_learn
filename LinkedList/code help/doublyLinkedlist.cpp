#include<bits/stdc++.h> 
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int data){
        this->data = data;
        this->next =NULL;
        this->prev =NULL;
    }
    ~Node(){
        int value =this->data;
        if(next!=NULL){
            delete next;
            next =NULL;
        }
        cout<<endl<<"memeoy free with value"<<value<<endl;
    }
};
void print(Node* &h){
    Node *temp=h;
    cout<<endl;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;

}
int getLength(Node* &h){
    //TODO:getting reference to change original head in linked list
    int len=0;
    Node* temp=h;
    while (temp!=NULL)
    {
        len++;
        temp= temp->next;
    }
    return len;
}
void insertAtHead(Node* &h,Node* &t, int data){
    Node *newNode = new Node(data);
    if(h ==NULL){
        h =newNode;
        t =newNode;
        return;
    }
    newNode->next =h;
    h->prev =newNode;
    h= newNode;
}
void insertAtTail(Node* &h,Node* &t,int data){
    Node *newNode = new Node(data);
    if (t ==NULL)
    {
        t=newNode;
        h=newNode;
    }
    
    t->next =newNode;
    newNode->prev =t;
    t= newNode;
}
void insertAtAny(Node* &h,Node* &t,int pos,int data){
    Node* temp=h;
    //insert at start
    if(pos==1){
        insertAtHead(h,t,data);
        return;
    }
    int  c=1;
    while (pos-1>c)
    {
        temp=temp->next;
        c++;
    }
    //insert at end
    if(temp->next ==NULL){
        insertAtTail(h,t,data);
        return;
    }
    //insert at between
    Node* nodeToInsert =new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev =nodeToInsert;
    temp->next =nodeToInsert;
    nodeToInsert->prev =temp;
    
    
}
void DeleteUsingPos(Node* &h,Node* &tail,int pos){
    Node* curr=h,*previos;
    int c=1;
    if(pos ==1){
        curr->next->prev =NULL;
        h =curr->next;
        curr->next=NULL;
        delete curr;
    }
    else{
        while (pos>c)
        {
            previos=curr;
            curr=curr->next;
            c++;
        }
        previos->next =curr->next;
        curr->prev =NULL;
        curr->next=NULL;
        delete curr;
        if (previos->next ==NULL)
        {
            tail =previos;
        }
        else{
            previos->next->prev= previos;
        }
    }
}
int main(){
    Node * h =NULL; 
    Node * t =NULL; 
    insertAtHead(h,t,9);
    print(h);
    insertAtHead(h,t,23);
    print(h);
    insertAtHead(h,t,3);
    print(h);
    insertAtHead(h,t,17);
    print(h);
    insertAtTail(h,t,67);
    print(h);
    cout<<h->data<<" head:"<<endl;
    cout<<t->data<<" tail:"<<endl;
    insertAtAny(h,t,5,56);
    print(h);
    DeleteUsingPos(h,t,6);
    print(h);
    int l=getLength(h);
    cout<<"length: "<<l;
}