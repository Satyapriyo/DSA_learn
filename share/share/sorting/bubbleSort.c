#include<stdio.h>
void display(int arr[],int n){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}
void bubbleSort(int arr[],int n){
    int i,j,c;
    for(i=0;i<n;i++){
        for ( j=0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                c=arr[j];
                arr[j]=arr[j+1];
                arr[j+1] =c;
            }
        }
    }
}

int main(){
    int i=0,n;
    printf("enter length of array\n");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    display(arr,n);
}