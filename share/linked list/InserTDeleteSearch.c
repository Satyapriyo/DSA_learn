#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *create(struct node *h)
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
void search(struct node *h)
{
    int d ,flag =1,s;
    printf("enter the the data of that node\n");
    scanf("%d",&s);
    struct node *temp;
    temp=h;
    while(temp!=NULL)
    {
	    if (s ==temp->data)
        {
            flag =0;
            break;
        }
        temp = temp->next;
	}
	if(flag ==0)
        printf("data is found \n");
    else
        printf("not found");

}
struct node *insert(struct node *h)
{
	struct node *temp,*t=h,*Q,*T;
	int p,count=0,c=1;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter data");
	scanf("%d",&temp->data);
	printf("\n Enter position");
	scanf("%d",&p);
	temp->next=NULL;
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
struct node *delete(struct node *h)
{
	struct node *temp,*t=h,*Q,*T;
	int p,count=0,c=1;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("\n Enter position");
	scanf("%d",&p);
	if(p==1)
	{
		h=t->next;
		free(t);
	}
	else{
        while(c<p-1)
	{
        Q=t;
	 t=t->next;
	 c++;
	 }
	//ENTER AT LAST
	  if(t->next==NULL)
	 {
		Q->next=NULL;
        free(t);
	 }
	 else  // at any position
	 {
		Q=t->next;
		T= Q->next;
		t->next=T;
        free(Q);
	 }

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
	printf("\n PRESS 4 TO delete:");
	printf("\n PRESS 5 TO search:");
	printf("\n PRESS 6 TO Exit:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		head=create(head);
		break;
		case 2:
		display(head);
		break;
		case 3:
		head=insert(head);
		break;
        case 4:
		head=delete(head);
		break;
        case 5:
		search(head);
		break;
		case 6:
		exit(0);	
	}
}
return 0;
}
