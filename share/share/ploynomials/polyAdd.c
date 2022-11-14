#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct pNode{
    int exp;
    int coff;
    struct pNode *next;
};
struct pNode* polyadd(struct pNode *h1,struct pNode *h2){
    struct pNode* t1=h1;
    struct pNode* t2=h2;
    struct pNode* tr=NULL,*newNode;
    newNode =(struct pNode*)malloc(sizeof(struct pNode));
    tr=newNode;
    newNode->next =NULL;
    while (t1!=NULL && t2!=NULL)
    {
        if(t1->exp > t2->exp){
            newNode->exp=t1->exp;
            newNode->coff=t1->coff;
            t1=t1->next;
        }
        else if(t1->exp < t2->exp){
            newNode->exp=t2->exp;
            newNode->coff=t2->coff;
            t2=t2->next;
        }
        else{
            newNode->coff=t2->coff + t1->coff;
            newNode->exp=t1->exp;
            t1=t1->next;
            t2=t2->next;
        }
        newNode->next = (struct pNode*)malloc(sizeof(struct pNode));
        newNode = newNode->next;
        newNode->next =NULL;
    }
    
    while(t2!=NULL || t1!=NULL)
    {
        if(t1!=NULL){
            newNode->exp =t1->exp;
            newNode->coff =t1->coff;
            t1=t1->next;
        }
        else if(t2!=NULL){
            newNode->exp =t2->exp;
            newNode->coff =t2->coff;
            t2=t2->next;
        }
        newNode->next = (struct pNode*)malloc(sizeof(struct pNode));
        newNode = newNode->next;
        newNode->next =NULL;
    }
    //newNode->next =NULL;
    return tr;
}
struct pNode* insert(struct pNode *h){
    struct pNode *newNode,*q;
    q = h;
    newNode = (struct pNode*)malloc(sizeof(struct pNode));
    // if(newNode ==NULL){
    //     printf("allocation error!\n");
    //     exit(0);
    // }
    printf("\nenter cofficient\n");
    scanf("%d",&newNode->coff);
    printf("\nenter power\n");
    scanf("%d",&newNode->exp);
    newNode->next =NULL;
    if(h==NULL){
        h=newNode;
    }
    else{
        while(q->next !=NULL){
            q=q->next;
        }
        q->next = newNode;
    }
    return h;  
}
void display(struct pNode *h){
    struct pNode *t=h;
    if(t==NULL) return;
    while (t->next!=NULL)
    {
        printf("%dX^%d +",t->coff,t->exp);
        t=t->next;
    }
    printf("\n");
}
int main(){
    struct pNode *p1=NULL,*p2=NULL,*pr=NULL;
    int ch;
    printf("enter 1 to insert in 1st polynomial addition\n");
    printf("enter 2 to insert in 2nd polynomial addition\n");
    printf("enter 3 to add both polynomial\n");
    printf("enter 4 to display 1st poly\n");
    printf("enter 5 to display 2nd poly\n");
    printf("enter 6 to display result\n");
    printf("enter 7 to exit\n");
    while (1)
    {
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                p1=insert(p1);
                break;
            case 2:
                p2=insert(p2);
                break;
            case 3:
                pr=polyadd(p1,p2);
                break;
            case 4:
                display(p1);
                break;
            case 5:
                display(p2);
                break;
            case 6:
                display(pr);
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
