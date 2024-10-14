#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5
#define LOAD_FACTOR_THRESHOLD 0.7

typedef struct HashTable {
    int *table;
    int size;
    int count; // number of elements in the hash table
} HashTable;

int hashFunction(int key, int size) {
    return key % size;
}

HashTable* createHashTable(int size) {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->count = 0;
    ht->table = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = -1; // -1 indicates empty slot
    }
    return ht;
}

void rehash(HashTable *ht) {
    int oldSize = ht->size;
    int *oldTable = ht->table;

    ht->size *= 2; // double the size
    ht->table = malloc(sizeof(int) * ht->size);
    for (int i = 0; i < ht->size; i++) {
        ht->table[i] = -1; // initialize new table
    }

    ht->count = 0; // reset count for new rehash
    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i] != -1) {
            // Re-insert the old keys
            insert(ht, oldTable[i]);
        }
    }
    free(oldTable); // free old table
}

void insert(HashTable *ht, int key) {
    if ((float)ht->count / ht->size >= LOAD_FACTOR_THRESHOLD) {
        rehash(ht);
    }

    int index = hashFunction(key, ht->size);
    while (ht->table[index] != -1) {
        index = (index + 1) % ht->size; // linear probing for open addressing
    }
    ht->table[index] = key;
    ht->count++;
    printf("%d inserted at index %d\n", key, index);
}

void delete(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    while (ht->table[index] != -1) {
        if (ht->table[index] == key) {
            ht->table[index] = -1; // Mark as deleted
            ht->count--;
            printf("%d deleted from index %d\n", key, index);
            return;
        }
        index = (index + 1) % ht->size; // Continue searching
    }
    printf("%d not found in the hash table\n", key);
}

void search(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    while (ht->table[index] != -1) {
        if (ht->table[index] == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % ht->size; // Continue searching
    }
    printf("%d not found in the hash table\n", key);
}

void printHashTable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] != -1) {
            printf("Index %d: %d\n", i, ht->table[i]);
        } else {
            printf("Index %d: empty\n", i);
        }
    }
}

void freeHashTable(HashTable *ht) {
    free(ht->table);
    free(ht);
}

int main() {
    HashTable *ht = createHashTable(INITIAL_SIZE);
    
    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 40);
    insert(ht, 50); // This will trigger a rehash

    printf("\nHash Table after insertions:\n");
    printHashTable(ht);

    search(ht, 30);
    search(ht, 99);

    delete(ht, 20);
    delete(ht, 99);

    printf("\nHash Table after deletions:\n");
    printHashTable(ht);

    freeHashTable(ht);
    return 0;
}
