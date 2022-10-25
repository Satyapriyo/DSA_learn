#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct pNode{
    int exp;
    float coff;
    struct pNode *next;
};
void insert(struct pNode **head,int e,float x){
    struct pNode *prev , *new,*q;
    q =*head;
    new = (struct pNode*)malloc(sizeof(struct pNode));
    if(new ==NULL){
        printf("allocation error!\n");
        exit(0);
    }
    
}
