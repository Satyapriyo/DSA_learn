#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *insertAtBeg(struct node* h){
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    printf("enter the data \n");
    scanf("%d",&temp->data);
    temp->next =NULL;
    if (h == NULL)
    {
        h = temp;
    }
    else{
        temp->next = h;
        h= temp;
    }
    return h;
}
void print(struct node* h){
    struct node *temp=h;
    while (temp!= NULL)
    {
        printf("%d ",temp->data);
        temp =temp->next;
    }
    printf("\n");
}
// struct node* Delete(struct node *head);
// void append(struct node* head);
int main(){
    struct node *head = NULL;
    while(1){
    printf("enter 1 to insert at begining\n");
    printf("enter 3 to print \n");
    printf("enter 4 to  append\n");
    printf("enter 5 to insert at any position \n");
    printf("enter 6 to  \n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
        {
        case 1:
            head=insertAtBeg(head);
            break;
        case 2:
            print(head);
            break;
        // case 3:
        //     append(head);
        //     break;
        // case 3:
        //     head=Delete(head);
        //     break;
        case 6:
            exit(0);
            break;
        default:
            // exit(0);
            break;
        }
    }
}