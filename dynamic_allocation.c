#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc to allocate a block of memory for an array of integers
    int* mallocArray = (int*)malloc(5 * sizeof(int));
    if (mallocArray == NULL) {
        printf("Memory allocation failed using malloc\n");
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        mallocArray[i] = i * 20;
    }
    printf("Values in mallocArray: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", mallocArray[i]);
    }
    printf("\n");
    free(mallocArray); // Free the allocated memory

    // Using calloc to allocate and zero-initialize an array of integers
    int* callocArray = (int*)calloc(5, sizeof(int));
    if (callocArray == NULL) {
        printf("Memory allocation failed using calloc\n");
        return 1;
    }
    printf("Values in callocArray (initialized to zero): ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", callocArray[i]);
    }
    printf("\n");
    free(callocArray); // Free the allocated memory

    // Using realloc to resize a previously allocated block of memory
    int* reallocArray = (int*)malloc(5 * sizeof(int));
    if (reallocArray == NULL) {
        printf("Memory allocation failed using malloc for reallocArray\n");
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        reallocArray[i] = i * 30;
    }
    reallocArray = (int*)realloc(reallocArray, 10 * sizeof(int));
    if (reallocArray == NULL) {
        printf("Memory reallocation failed using realloc\n");
        return 1;
    }
    for (int i = 5; i < 10; ++i) {
        reallocArray[i] = i * 30;
    }
    printf("Values in reallocArray after reallocation: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", reallocArray[i]);
    }
    printf("\n");
    free(reallocArray); // Free the allocated memory

    return 0;
}
