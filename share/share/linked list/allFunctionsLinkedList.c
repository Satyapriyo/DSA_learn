#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* insert(struct node *h){
    struct node *temp,*t=h,*last=h ,*after;
    temp = (struct node*)malloc(sizeof(struct node));
    int pos,data,count=0,c=0;
    printf("enter the data:\n");
    scanf("%d",&temp->data);
    printf("enter the position\n");
    scanf("%d",pos);
    temp->next = NULL;
    while(last->next!=NULL){
        count++;
        last=last->next;
    }
    if(pos>=count+1){
        printf("please enter a possible position\n");
        return h;
    }
    if(pos == 1){
        temp->next=h;
        h=temp;
    }
    t=h;
    while(c<pos-1){
            c++;
            t= t->next;
    }     
    //last node insert  
    if(t->next==NULL){
        t->next = temp;
    }
    else{
        after = t->next;
        t->next =temp;
        temp->next=after;
    }
    return h;
}
struct node* append(struct node *h){
    struct node *temp,*t=h;
    temp = (struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("underflow  \n");
    }
    while (t->next!=NULL)
    {
        t= t->next;
    }
    return h;

}
struct node* reverse(struct node *h);
void delete(struct node *h);
void print(struct node *h){
    struct node *temp=h;
    while(temp!=NULL){
        printf("%d-> ", temp->next);
        temp = temp->next;
    }

}

int main(){
   struct node *head=NULL;
   int sw; 
   printf("enter 1 to insert: \n") ;
   printf("enter 2 to print: \n") ;
   printf("enter 3 to exit: \n") ;
   while(1){
    int sw;
    printf("enter your choice\n");
    scanf("%d",&sw);
    switch(sw){
        case 1:
            head = insert(head);
            break;
        case 2:
            print(head);
            break;
        case 3:
            exit(0);
            break;
    }
   }
}