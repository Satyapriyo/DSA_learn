#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
    Node(int data){
        this->data =data;
        this->next =NULL;
    }
    ~Node(){
        int value=this->data; 
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"deleted "<<value;
    }
};
void insertAtHead(Node* &h,int data){
    //TODO:getting reference to change original head in linked list
    Node* temp =new Node(data);
    temp->next =h;
    h= temp;
    return;
}
void insertAtTail(Node* &t,int data){
    //TODO:getting reference to change original head in linked list
    Node* temp =new Node(data);
    t->next =temp;
    t= t->next;
    return;
}
void insertAtAny(Node* &h,Node *&t,int data,int pos){
    //TODO:getting reference to change original head in linked list
    Node* temp=h;
    //insert at start
    if(pos==1){
        insertAtHead(h,data);
    }
    Node* nodeToInsert =new Node(data);
    //insert at between
    int  c=1;
    while (pos-1>c)
    {
        temp=temp->next;
        c++;
    }
    nodeToInsert->next = temp->next;
    temp->next =nodeToInsert;
    //insert at end
    if(nodeToInsert->next ==NULL)
        t=nodeToInsert;
        return;
}
void DeleteUsingPos(Node* &h,Node* &tail,int pos){
    Node* temp=h,*t;
    int c=1;
    if(pos ==1){
        h =temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        while (pos>c)
        {
            t=temp;
            temp=temp->next;
            c++;
        }
        t->next =temp->next;
        temp->next=NULL;
        delete temp;
        if (t->next ==NULL)
        {
            tail =t;
        }
    }
}
void print(Node* &h){
    Node* temp=h;
    cout<<endl;
    while (temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* newNode = new Node(8);
    // cout<<newNode->data<<endl;
    // cout<<newNode->next<<" ";
    Node* h =  newNode;
    Node* t =  newNode;
    insertAtHead(h,12);
    insertAtHead(h,9);
    insertAtAny(h,t,189,4);
    insertAtTail(t,15);
    print(h);
    DeleteUsingPos(h,t,5);
    print(h);
    cout<<" \nhead "<<h->data<<endl;
    cout<<" \nTail "<<t->data<<endl;
    
}