#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct pNode{
    int exp;
    int coff;
    struct pNode *next;
};
struct pNode* insertPoly(struct pNode *h, int coff ,int pow){
    struct pNode *newNode,*q;
    q = h;
    newNode = (struct pNode*)malloc(sizeof(struct pNode));
    newNode->coff =coff;
    newNode->exp =pow;
    // if(newNode ==NULL){
    //     printf("allocation error!\n");
    //     exit(0);
    // }
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
struct pNode* removeDuplicates(struct pNode* start)
{
    struct pNode *ptr1, *ptr2, *dup;
    ptr1 = start;
  
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
  
        // Compare the picked element
        // with rest of the elements
        while (ptr2->next != NULL) {
  
            // If powerer of two elements are same
            if (ptr1->exp == ptr2->next->exp) {
  
                // Add their coefficients and put it in 1st element
                ptr1->coff = ptr1->coff + ptr2->next->coff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                dup->next=NULL;
                // remove the 2nd element
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
struct pNode* polymultiply(struct pNode* poly1, struct pNode* poly2)
{
  
    // Create two pointer and store the
    // address of 1st and 2nd polynomials
    struct pNode *ptr1, *ptr2,*poly3=NULL;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
  
            // Multiply the coefficient of both
            // polynomials and store it in coeff
            coeff = ptr1->coff * ptr2->coff;
  
            // Add the powerer of both polynomials
            // and store it in power
            power = ptr1->exp + ptr2->exp;
  
            // Invoke addnode function to create
            // a newnode by passing three parameters
            poly3 = insertPoly(poly3,coeff,power);
  
            // move the pointer of 2nd polynomial
            // two get its next term
            ptr2 = ptr2->next;
        }
  
        // Move the 2nd pointer to the
        // starting point of 2nd polynomial
        ptr2 = poly2;
  
        // move the pointer of 1st polynomial
        ptr1 = ptr1->next;
    }
  
    // this function will be invoke to add
    // the coefficient of the elements
    // having same powerer from the resultant linked list
    removeDuplicates(poly3);
    return poly3;
}

void display(struct pNode *h){
    struct pNode *t=h;
    if(t==NULL) return;
    while (t!=NULL)
    {
        printf("%dX^%d +",t->coff,t->exp);
        t=t->next;
    }
    printf("\n");
}
int main(){
    struct pNode *p1=NULL,*p2=NULL,*pr=NULL;
    int ch,coff,exp;
    printf("enter 1 to insert in 1st polynomial addition\n");
    printf("enter 2 to insert in 2nd polynomial addition\n");
    printf("enter 3 to multiply both polynomial\n");
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
                printf("\nenter cofficient\n");
                scanf("%d",&coff);
                printf("\nenter power\n");
                scanf("%d",&exp);
                p1=insertPoly(p1,coff,exp);
                break;
            case 2:
                printf("\nenter cofficient\n");
                scanf("%d",&coff);
                printf("\nenter power\n");
                scanf("%d",&exp);
                p2=insertPoly(p2,coff,exp);
                break;
            case 3:
                pr=polymultiply(p1,p2);
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
