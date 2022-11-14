#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *append(struct node *h)
{
	struct node *temp, *temp1;
	temp= (struct node *)malloc(sizeof(struct node));
	printf("\n Enter Data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(h==NULL)
	{
	h=temp;
	}
	
	else
	{
	temp1=h;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;	
	}
	temp1->next=temp;
    }
	return h;
}
void display(struct node *h)
{
struct node *temp;
temp=h;
while(temp!=NULL)
{
	printf("%d->",temp->data);
	temp=temp->next;
	}	
}
struct node *insert(struct node *h)
{
	struct node *temp,*t=h,*Q,*T;
	int p,count=0,c=1;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter data");
	scanf("%d",&temp->data);
	temp->next=NULL;
	printf("\n Enter position");
	scanf("%d",&p);
		while(t->next!=NULL)
	{
		count++;
		t=t->next;
	}
	// ENTER AT 1ST POSITION
	if(p==1)
	{
		temp->next=h;
		h=temp;
	}
	t=h;

	while(c<p-1)
	{
	 t=t->next;
	 c++;
	 }
	//ENTER AT LAST
	  if(t->next==NULL)
	 {
		t->next=temp;
	 }
	 else  // at any position
	 {
		Q=t->next;
		t->next=temp;
		temp->next=Q;

	 }
		return h;
	}
int main()
{
	struct node *head=NULL;
	while(1)
	{
	int ch;
	printf("\n PRESS 1 TO CREATE:");
	printf("\n PRESS 2 TO DISPLAY:");
	printf("\n PRESS 3 TO INSERT:");
	printf("\n PRESS 5 TO Exit:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		head=append(head);
		break;
		case 2:
		display(head);
		break;
		case 3:
		head=insert(head);
		break;
		case 5:
		exit(0);	
	}
}
return 0;
}
