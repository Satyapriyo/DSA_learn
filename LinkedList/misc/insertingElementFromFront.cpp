#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* next;
};
struct node* head;
void print(){
    node* temp =head;
    cout<<"the list\n";
    while (temp!=NULL)
    {
        cout<<temp ->data<<" ";
        temp= temp->next;
    }
    cout<<'\n';
}
void insert(int x){
    node* temp =new node();
    temp -> data= x;
    temp -> next = head;
    head = temp;
}
int main(){
    int n,i,x;
    head = NULL;
    cout<<"how many numbers you want to insert in the list\n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the number\n";
        cin>>x;
        insert(x);
        print();
    }
    return 0;
}