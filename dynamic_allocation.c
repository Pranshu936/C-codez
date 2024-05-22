#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc to allocate a block of memory for a single integer
    int *singleInt = (int*)malloc(sizeof(int));
    if (singleInt == NULL) {
        fprintf(stderr, "Memory allocation failed using malloc\n");
        return 1;
    }
    *singleInt = 42;
    printf("Value of singleInt: %d\n", *singleInt);
    free(singleInt); // Free the allocated memory

    // Using malloc to allocate a block of memory for an array of integers
    int *mallocArray = (int*)malloc(5 * sizeof(int));
    if (mallocArray == NULL) {
        fprintf(stderr, "Memory allocation failed using malloc\n");
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        mallocArray[i] = i * 10;
    }
    printf("Values in mallocArray: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", mallocArray[i]);
    }
    printf("\n");
    free(mallocArray); // Free the allocated memory

    // Using calloc to allocate and zero-initialize an array of integers
    int *callocArray = (int*)calloc(5, sizeof(int));
    if (callocArray == NULL) {
        fprintf(stderr, "Memory allocation failed using calloc\n");
        return 1;
    }
    printf("Values in callocArray (initialized to zero): ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", callocArray[i]);
    }
    printf("\n");
    free(c
