b#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
 	struct node *next;
};
struct node* insert (struct node* h){
	struct node *temp1;
	int data;
	printf("enterr the data\n");
	scanf("%d",&data);
	temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data =data;
	temp1->next =NULL;
	if(h==NULL){
		h=temp1;
	}
	else{
		temp1->next=h;
		h=temp1;
	}
}
void print (struct node* h){
	struct node *temp1=h;
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		temp1=temp1->next;

	}
}
struct node *delet (struct node* h);
int main(){
	struct node *h = NULL;
	int ch;
	printf("enter 1 to insert\n");
	printf("enter 2 to delete\n");
	printf("enter 3 to print\n");
	printf("enter 4 to exit\n");
	while(1){
		switch(ch){
			case 1:
				h=insert(h);
				break;
			case 2:
				h=delet(h);
				break;
			case 3:
				print(h);
				break;
			case 4:
				exit(0);

		}
	}
	return 0;
}