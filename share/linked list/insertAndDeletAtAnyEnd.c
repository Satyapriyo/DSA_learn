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
struct node* delet(struct node* h){
    struct node *temp=h,*t;
    int count=0,position,c=0;
    while (temp!=NULL)
    {
        count++;
        temp =temp->next;
    }
    printf("enter the position of node to delet\n");
    scanf("%d",position);
    if(position==0 || position<0)
        printf("enter a positive and non zero position\n");
    else if (position == 1)
    {
        temp = h;
        h= temp->next;
        temp->next =NULL;
        free(temp);
    }
    // else if(position>1 && position<= count){
    //     temp=h;
    //     while(c<position-1)
    //         temp=temp->next;
    //     t=temp->next;
    //     temp->next->next = temp->next;
    //     free(temp);
    // }
    return h;
}
int main(){
	struct node *head=NULL;
	while(1)
	{
	int ch;
	printf("\n PRESS 1 TO CREATE:");
	printf("\n PRESS 2 TO DISPLAY:");
    printf("\n PRESS 3 TO DELET:");
	printf("\n PRESS 4 TO EXIT:");
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
		head=delet(head);
		break;
		case 4:
		exit(0);	
	}
}
return 0;
}
