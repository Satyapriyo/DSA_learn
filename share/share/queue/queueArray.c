#include<stdio.h>
#include<stdlib.h>
# define MAX 6
int queue[5];
int front=-1,rear =-1;
void enque(int data){
    if(rear ==MAX-1){
        printf("queue is full");
    }
    else {
        rear =rear +1;
        queue[rear] =data;
        if(front == -1)
            front++;
    }
    return;
}
int deque(){
    int i;
    printf("%d", front);
    printf("%d", rear);
    if(front+1 ==-1 || front >rear){
        printf("queue empty");
    }
    else {
        front  =front +1;
        i = queue[front];
    }
    return i;
}
void display(){
    int i;
    for ( i = front+1; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
    return;
}
int main(){
    int ch;
    printf("\nenter 1 to enque\n");
    printf("\nenter 2 to deque\n");
    printf("\nenter 3 to display\n");
    
    while (1)
    {
        printf("\nenter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            int n;
            printf("\nenter data\n");
            scanf("%d",&n);
            enque(n);
            break;
        case 2:
            n=deque();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
    
//  enque(2);
//  enque(8);
//  enque(3);
//  enque(9);
//  display();
//  printf("%d ",deque());
//  display();
return 0;
}