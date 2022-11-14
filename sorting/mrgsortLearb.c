#include<stdio.h>
#include<stdlib.h>
void print(int arr[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
}
void merge(int arr[], int l,int mid,int h){
    
    int i=0,j=0,k=l;
    int n1=mid-l+1;
    int n2=h-mid;
    int A1[n1],A2[n2];
    for (i = 0; i < n1; i++)
    {
        A1[i] =arr[l+i];
    }
    for (i = 0; i < n2; i++)
    {
        A2[i] =arr[mid+i+1];
    }
    i=0;
    while (i<n1 && j<n2)
    {
        if(arr[i]<arr[j]){
            arr[k] =A1[i];
            j++;
        }
        else{
            arr[k]=A2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=A1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=A1[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main(){
    int arr[5] ={2,3,1,9,7};
    int n=5;
    print(arr,n);
    mergeSort(arr,0,4);
    print(arr,n);
}
