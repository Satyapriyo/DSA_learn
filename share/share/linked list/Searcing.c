#include <stdio.h>
#include<process.h>
void bionarySearch(int a[], int n,int target){
    int start =0, end=n-1, mid;
    while (start <= end)
    {
        mid = start + (end - start)/2;
        if (a[mid]==target )
        {
            break;
        }
        else if (a[mid]>target)
        {
            end = mid -1;
        }
        else
            start = mid +1;
    }
    if (a[mid] == target)
    {
        printf("element found at index %d",mid+1);
    }
    else
        printf("element not found");
}
void linearSearch(int a[], int n,int target){
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i]==target)
        {
            break;
        }
    }
    if (a[i] == target)
    {
        printf("element found at index %d",i+1);
    }
    else
        printf("element not found");
}
int main()
{
	int array[100],n,i,choice,target;
	printf("Enter number of elements: ");
  	scanf("%d",&n);
	printf("Enter %d integers: ", n);
  	for (i= 0; i < n; i++)
    	scanf("%d",&array[i]);
    printf("enter the element to find:" );
    scanf("%d",&target);
    while(1)
    {
    	printf("\nPress 1 for linear search");
    	printf("\nPress 2 for bionary search");
    	printf("\nPress 3 to exit");
    	printf("\nEnter your choice: ");
	    scanf("%d",&choice);
 		switch (choice)
 		{
 			case 1: linearSearch(array,n,target);
 					break;
 			case 2: bionarySearch(array,n,target);
 					break;
 			case 3: exit(0);
		}
	}
	return 0;
}