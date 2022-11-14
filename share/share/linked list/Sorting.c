#include <stdio.h>
#include<process.h>
void bubblesort(int array[],int n)
{
  int i, j,temp;

  for (i = 0 ; i < n ; i++)
  {
    for (j = 0 ; j < n - 1; j++)
    {
      if (array[j] > array[j+1]) 
      {
        temp = array[j];
        array[j]   = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  printf("Sorted list in ascending order:\n");
	for (i = 0; i < n; i++)
     printf("%d\n", array[i]);
}

void selectionSort(int array[], int n)
{
    int i, j, min,temp;
	for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
          	if (array[j] < array[min])
          	{
            	min= j;
		  	}
            if(min!= i)
            {
            	temp=array[i];
            	array[i]=array[min];
            	array[min]=temp;
            }
    	}
    }
    printf("Sorted list in ascending order:\n");
	for (i = 0; i < n; i++)
    	printf("%d\n", array[i]);
}

int main()
{
	int array[100],n,i,choice;
	printf("Enter number of elements: ");
  	scanf("%d",&n);
	printf("Enter %d integers: ", n);
  	for (i= 0; i < n; i++)
    	scanf("%d",&array[i]);
    while(1)
    {
    	printf("\nPress 1 for Bubble sort");
    	printf("\nPress 2 for Selection sort");
    	printf("\nPress 3 to exit");
    	printf("\nEnter your choice: ");
	    scanf("%d",&choice);
 		switch (choice)
 		{
 			case 1: bubblesort(array,n);
 					break;
 			case 2: selectionSort(array,n);
 					break;
 			case 3: exit(0);
		}
	}
	return 0;
}