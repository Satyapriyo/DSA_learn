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
        if(next!=NULL){
            delete next;
            next=NULL;
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
Node* removeNthFromEnd(Node* head,int n){
    int size=0,count=0;
    Node* temp=head , *t;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    // cout<<endl<<size;
    temp=head;
    size =size-n;
    while (size-1>count)
    {
        count++;
        temp=temp->next;
    }
    if (head == temp && temp->next==NULL)
    {
        head =NULL;
        delete temp;
        return head;
    }
    else if(head == temp)
    {
        head = temp->next;
        temp->next =NULL;
        delete temp;
        return head;
    }
    else
    {
        t=temp->next;
        temp->next = t->next;
        t->next =NULL;
        delete t;
        return head;
    }
    return head;
}
void removeNthFromEndFastSlow(Node * &h,int n){
        Node* fast =h,*slow =h;
        for(int i=0;i<n;i++){
            fast =fast->next;
        }
        if(fast==NULL){
            h =h->next;
        }
        while(fast->next!=NULL){
            fast =fast->next;
            slow =slow->next;
        }
        slow->next =slow->next->next;
}
int main(){
   Node* newNode = new Node(8);
    // cout<<newNode->data<<endl;
    // cout<<newNode->next<<" ";
    Node* h =  newNode;
    insertAtHead(h,12);
    insertAtHead(h,9);
    print(h); 
    removeNthFromEndFastSlow(h,2);
    print(h); 
}