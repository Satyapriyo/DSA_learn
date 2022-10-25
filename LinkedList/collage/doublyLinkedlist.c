#include<stdio.h>
#include<stdlib.h>
#include<process.h>
// node structure to  create a linked list
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
//insert a new node at any position
struct node* insert(struct node* h){
	struct node* newNode,*t,*q;
	newNode =(struct node*)malloc(sizeof(struct node));
	int pos , c=1;
	printf("\n enter the data: ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	newNode->prev=NULL;
	printf("\nenter a position to insert:");
	scanf("%d",&pos);
	if(pos==1){
		newNode->next= h;
		h= newNode;
	}
	else{
		t=h;
		while (pos-1>c){
			t=t->next;
			c++;
		}
		if(t->next==NULL){
			t->next = newNode;
			newNode->prev =t;
		}
		q =t->next;
		t->next =newNode;
		newNode->prev= t;
		newNode->next =q;
		q->prev =newNode;
	}
	return h;
}
//create a new node and add it in the last pos
struct node* create(struct node* h){
	struct node* newNode,*t=h;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter the data: ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	newNode->prev=NULL;
	if(h==NULL){
		h=newNode;
	}
	else
	{
		while(t->next!=NULL){
			t=t->next;
		}
		t->next =newNode;
		newNode->prev= t;
	}
	return h;
}
//display the list 
void print(struct node* h){
	struct node* t=h;
	while(t!=NULL){
		printf("%d->",t->data);
		t=t->next;
	}
}
int main(){
	int choice;
	struct node* h=NULL;
	while(1){
		printf("\nenter 1 to create:");
		printf("\nenter 2 to print:");
		printf("\nenter 3 to insert:");
		printf("\nenter 4 to exit:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				h= create(h);
				break;
			case 2:
				print(h);
				break;
			case 3:
				h=insert(h);
				break;			
			case 4:
				exit(0);
		}
	}
	return 0;
}
