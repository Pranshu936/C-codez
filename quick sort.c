
//quick sort
#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}



// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int partionindex = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, partionindex - 1);
        quickSort(arr, partionindex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int arr[] = {8,9,3,6,4,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
