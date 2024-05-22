//insertion sort
#include<stdio.h>
void intertionsortr(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }
}

int main() {
    int arr[] = {8,9,3,6,4,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    intertionsortr(arr,n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}