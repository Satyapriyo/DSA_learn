#include<stdio.h>
#include<stdlib.h>
# define MAX 10
int queue[MAX];
int front=-1,rear =-1;
void enque(){
    int data;
    printf("enter the data\n");
    scanf("%d",&data);
    if(rear ==MAX-1){
        printf("queue is full");
    }
    else {
        if(front == -1){
            front =0;
        }
        rear =rear +1;
        queue[rear] =data;
    }
}
void deque(){
    if(front ==-1 || front >rear){
        printf("queue empty");
    }
    else {
        front  =front +1;
    }
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
    int choice;
    printf("\nPress 1 for enque sort");
    printf("\nPress 2 for deque sort");
    printf("\nPress 3 to print");
    printf("\nPress 4 to exit");
    while(1)
    {
    	
    	printf("\nEnter your choice: ");
	    scanf("%d",&choice);
 		switch (choice)
 		{
 			case 1: enque();
 					break;
 			case 2: deque();
 					break;
 			case 3: display();
                    break;
            case 4:
                    exit(0);
		}
	}
	return 0;
    /*
 enque(2);
 enque(8);
 enque(3);
 enque(9);
 display();
 printf("%d ",deque());
 display();
 */
}