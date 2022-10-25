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
    }
    return;
}
int deque(){
    int i;
    if(front ==-1 || front >rear){
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
    for ( i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
    return ;
}
int main(){
 enque(2);
 enque(8);
 enque(3);
 enque(9);
 display();
 printf("%d ",deque());
 display();
return 0;
}