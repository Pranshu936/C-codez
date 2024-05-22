//merge sort
#include<stdio.h>

void merge(int arr[],int mid,int low,int high){
    int i,j,k,b[100];
    i=low;j=mid+1;k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            i++;k++;
        }
        else{
            b[k]=arr[j];
            j++;k++;
        }
    }

    while(i<=mid){
        b[k]=arr[i];
        k++;i++;
    }

    while(j<=high){
        b[k]=arr[j];
        j++;k++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=b[i];
    }
}

void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,mid,low,high);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
}

int main(){
    int arr[] = {8,9,3,6,4,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr,0,6);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}