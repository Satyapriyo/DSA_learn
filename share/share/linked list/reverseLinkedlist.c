#include<stdio.h>
#include<stdlib.h>
// #include<process.h>

struct node
{
	int data;
	struct node *next;
};

struct node *append(struct node *head)
{
	struct node *temp,*last=head;
	temp= (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		last=temp;
	}
	else
	{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next = temp;
		last = temp;
	}
	return head;
 } 
 
struct node*insert(struct node *h)
{
	struct node *temp;
	int p,c=1;
	temp= (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	printf("\nEnter position: ");
	scanf("%d",&p);
	if(p==1)
	{
		temp->next=h;
		h=temp;
	}
	else
	{
		struct node *t=h,*q;
		while(c<p-1)
		{
			t=t->next;
			c++;
		}
		if(t->next==NULL)
		{
			t->next=temp;
		}
		else
		{
			q=t->next;
			t->next=temp;
			temp->next=q;
		}
	}
	return h;
}

struct node *reverse(struct node *p)
{
	struct node *l,*q,*n;
	q=p;
	l=NULL;
	n=q->next;
	while(q->next!=NULL)
	{
		q->next=l;
		l=q;
		q=n;
		n=q->next;
	}
	q->next=l;
	return q;
}
 
 void display(struct node *h)
 {
 	struct node *temp;
 	temp=h;
 	while( temp!= NULL)
 	{
 		printf("%d->\t",temp->data);
 		temp=temp->next;
	 }
 }
 
int main()
 {
 	struct node *head=NULL;
 	int choice;
 	
 		printf("\nPress 1 to append");
 		printf("\nPress 2 to display");
 		printf("\nPress 3 to insert");
 		printf("\nPress 4 to reverse");
 		printf("\nPress 5 to exit");
    while(1)
    {
	    printf("\nEnter your choice: ");
	    scanf("%d",&choice);
 		switch (choice)
	 {
	 	case 1: head=append(head);
	 			break;
	 	case 2: display(head);
	 			break;
	 	case 3: head=insert(head);
	 			break;	
		case 4: head=reverse(head);
	 			break;
	 	case 5: exit(0);
	 }
	}
	
}