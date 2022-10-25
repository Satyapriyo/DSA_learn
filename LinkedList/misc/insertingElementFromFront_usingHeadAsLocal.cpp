#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* next;
};
void print(node* head){
    cout<<"the list\n";
    while (head!=NULL)
    {
        cout<<head ->data<<" ";
        head= head->next;
    }
    cout<<'\n';
}
void insert(node** head,int x){
    node* temp =new node();
    temp -> data= x;
    temp -> next = *head;
    *head = temp;
}
int main(){
    int n,i,x;
    node* head =NULL;
    cout<<"how many numbers you want to insert in the list\n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the number\n";
        cin>>x;
        insert(&head,x);
        print(head);
    }
    return 0;
}