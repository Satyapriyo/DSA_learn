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
Node *reverseLinkedList(Node* h){
    Node *prev=h,*curr=prev->next,*t;
    prev->next =NULL;
    while (curr->next!=NULL)
    {
        t=prev;
        prev = curr;
        curr =curr->next;
        prev->next =t;
    }
    curr->next =prev;
    return curr;
}
int main(){
    Node* newNode = new Node(8);
    // cout<<newNode->data<<endl;
    // cout<<newNode->next<<" ";
    Node* h =  newNode;
    insertAtHead(h,12);
    insertAtHead(h,9);
    print(h);
    h=reverseLinkedList(h);
    print(h);
    h=reverseLinkedList(h);
    print(h);
}