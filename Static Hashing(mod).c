#include <stdio.h>

#define SIZE 7

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int value) {
    int index = hashFunction(value);
    if (hashTable[index] == -1) {
        hashTable[index] = value;
        printf("%d inserted at index %d\n", value, index);
    } else {
        printf("Collision at index %d, cannot insert %d\n", index, value);
    }
}

void delete(int value) {
    int index = hashFunction(value);
    if (hashTable[index] == value) {
        hashTable[index] = -1;
        printf("%d deleted from index %d\n", value, index);
    } else {
        printf("%d not found in the hash table\n", value);
    }
}

void search(int value) {
    int index = hashFunction(value);
    if (hashTable[index] == value) {
        printf("%d found at index %d\n", value, index);
    } else {
        printf("%d not found in the hash table\n", value);
    }
}

void print() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: empty\n", i);
        }
    }
}

int main() {
    init();
    insert(10);
    insert(3);
    insert(24);
    insert(15);
    printf("\nHash Table:\n");
    print();
    printf("\nSearching for 24:\n");
    search(24);
    printf("Searching for 99:\n");
    search(99);
    printf("\nDeleting 24:\n");
    delete(24);
    printf("Deleting 99:\n");
    delete(99);
    printf("\nHash Table after deletion:\n");
    print();
    return 0;
}
