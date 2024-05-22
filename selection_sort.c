//selection sort
#include<stdio.h>
void selectionsort(int arr[],int n){
    int i,j,min_ind;
    for(int i=0;i<n-1;i++){
        min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind=j;      
            }
            if(min_ind!=i){
                int temp=arr[min_ind];
                arr[min_ind]=arr[i];
                arr[i]=temp;
            }
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
    selectionsort(arr,n);
    printf("sorted array");
    print(arr,n);
    return 0;
}