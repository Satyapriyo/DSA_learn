#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	char name[20];
    int roll,marks;
	struct node *next;
};
struct node *append(struct node *h){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    printf("enter the name of the student \n");
    scanf("%s", temp->name);
    printf("enter the roll of the student \n");
    scanf("%d", &temp->roll);
    printf("enter the marks of the student \n");
    scanf("%d", &temp->marks);
    if(h==NULL){
        h=temp;
        temp->next= NULL;
    }
    else{
        struct node *t=h;
        while (t->next!=NULL)
        {
            t= t->next;
        }
        t->next=temp;
        temp->next= NULL;
    }
    return h;
}
void display(struct node *h){
    struct node *temp=h;
    while (temp !=NULL)
    {
        if(temp->marks > 90){
            printf("%s->%d,%d \n",temp->name,temp->roll,temp->marks);
        }
        temp = temp->next;
    }
}
int main()
{
	struct node *head=NULL;
	while(1)
	{
	int ch;
	printf("\n PRESS 1 TO CREATE:");
	printf("\n PRESS 2 TO DISPLAY:");
	printf("\n PRESS 3 TO Exit:");
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
		exit(0);	
	}
}
return 0;
}
