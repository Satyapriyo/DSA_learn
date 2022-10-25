#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;
void push(int num){
    if(top==MAX_SIZE-1){
        printf("Error stack overflow\n");
        return;
    }
    a[++top]=num;
}
void print(){
    int i;
    printf("stack :");
    for (int i = 0; i < top; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    push(2);
    print();
    push(18);
    print();
    push(3);
    print();
    push(7);
    print();
    push(8);
    print();
    return 0;
}
