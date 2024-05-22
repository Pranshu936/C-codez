#include <stdio.h>
#include <stdlib.h>
int main()
{
        int *arr;
        int size, newSize;
        printf("Enter the initial size of the array: ");
        scanf("%d", &size);
        arr = (int *)malloc(size * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory allocation failed. Exiting...\n");
            return 1;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = i + 1;
        }
        printf("Initial array contents:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Enter the new size of the array: ");
        scanf("%d", &newSize);
        arr = (int *)realloc(arr, newSize * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory reallocation failed. Exiting...\n");
            return 1;
        }
        for( int i = size; i < newSize; i++){
            arr[i]=0;
        }
        printf("Resized array contents:\n");
        for (int i = 0; i < newSize; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
        return 0;
}

