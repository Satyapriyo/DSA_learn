#include<stdio.h>
void display(int arr[], int n){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",arr[i]);
    }
}
void selectionsort(int arr[], int n){
    int i,j,min_idx,c;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++){
            if(arr[j]< arr[min_idx])
                min_idx =j;
        }
        if(min_idx !=i){
            c=arr[i];
            arr[i] =arr[min_idx];
            arr[min_idx] =c;
        }
    }
    display(arr,n);
}

int main(){
    int n,i;
    printf(" \nenter the array length: ");
    scanf("%d",&n);
    int arr[n];
    printf(" \nenter the array elements: ");
    for( i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    display(arr,n);
    return 0;
}