#include<stdio.h>
void print(int arr[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
}
void swap(int *a, int *b){
    int c;
    c= *a;
    *a =*b;
    *b =c;
}
int partition(int arr[],int l, int h){
    int i=l,j=h;
    int pivot=(l+h)/2;
    while (i<j)
    {
        while (arr[pivot]>=arr[i] &&i<h) i++;
        while (arr[pivot]<arr[j] && j>l) j--;
        if(i<j){
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[j],&arr[pivot]);
    return j;
}
void quickSort(int arr[],int l,int h){
    if(l<h){
        int pivot=partition(arr,l,h);
        quickSort(arr,l,pivot-1);
        quickSort(arr,pivot+1,h);
    }
}




int main(){
    int arr[5] ={2,3,1,9,7};
    int n=5;
    print(arr,n);
    quickSort(arr,0,4);
    print(arr,n);
}
