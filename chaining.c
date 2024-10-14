#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next; // Pointer to the next node in the linked list
} Node;

typedef struct HashTable {
    Node **table; // Array of pointers to linked lists (buckets)
    int size; // Number of buckets in the hash table
} HashTable;

int hashFunction(int key, int size) {
    return key % size; // Simple modulus hash function
}

HashTable* createHashTable(int size) {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL; // Initialize all buckets to NULL
    }
    return ht;
}

void insert(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->table[index]; // Insert at the beginning of the list
    ht->table[index] = newNode;
    printf("%d inserted at index %d\n", key, index);
}

void delete(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    Node *current = ht->table[index];
    Node *prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                // Deleting the first node in the list
                ht->table[index] = current->next;
            } else {
                // Deleting a node that is not the first
                prev->next = current->next;
            }
            free(current); // Free the memory
            printf("%d deleted from index %d\n", key, index);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("%d not found in the hash table\n", key);
}

void search(HashTable *ht, int key) {
    int index = hashFunction(key, ht->size);
    Node *current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the hash table\n", key);
}

void printHashTable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        Node *current = ht->table[i];
        printf("Index %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeHashTable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        Node *current = ht->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp); // Free each node
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    HashTable *ht = createHashTable(5); // Create hash table with 5 buckets

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 15);
    insert(ht, 25);
    insert(ht, 30);
    
    printf("\nHash Table after insertions:\n");
    printHashTable(ht);

    search(ht, 15);
    search(ht, 99);

    delete(ht, 20);
    delete(ht, 99);

    printf("\nHash Table after deletions:\n");
    printHashTable(ht);

    freeHashTable(ht);
    return 0;
}
