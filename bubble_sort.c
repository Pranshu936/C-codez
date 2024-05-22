//Bubble sort
#include<stdio.h>
void bubblesort(int arr[],int n){
    int i,j,swapped;
    for(i=0;i<n-1;i++){
        swapped=0;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
}

int main(){
    int arr[]={8,9,3,6,4,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    printf("sorted array is:");
    print(arr,n);
    return 0;
}