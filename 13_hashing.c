//Vedha Mahadevan
//B23CS1262
//Hashing : Separate Chaining & Collision Handling

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tableSize 10

struct Node {
    int data;
    struct Node* next;
};

struct HashTable {
    struct Node** table;
};

struct SearchResult {
    struct Node* node;
    int index;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->table = (struct Node**)malloc(tableSize * sizeof(struct Node*));
    for (int i = 0; i < tableSize; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

int hashFunction(int keyvalue) {
    return keyvalue % tableSize;
}

void insert(struct HashTable* hashTable, int keyvalue) {
    int hashIndex = hashFunction(keyvalue);
    struct Node* newNode = createNode(keyvalue);
    newNode->next = hashTable->table[hashIndex];
    hashTable->table[hashIndex] = newNode;
}

struct SearchResult search(struct HashTable* hashTable, int keyvalue) {
    int hashIndex = hashFunction(keyvalue);
    struct Node* current = hashTable->table[hashIndex]; 
    struct SearchResult result;
    result.node = NULL;
    result.index = -1;

    while (current != NULL) {
        if (current->data == keyvalue) {
            result.node = current; 
            result.index = hashIndex; 
            return result; 
        }
        current = current->next;
    }
    return result; 
}

void display(struct HashTable* hashTable) {
    for (int i = 0; i < tableSize; i++) {
        struct Node* current = hashTable->table[i];
        printf("Index %d : ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void main() {
    struct HashTable* hashTable = createHashTable();
    int n, keyvalue, searchelement;

    printf("Enter the number of keys in the hash table : ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Enter key %d : ", i + 1);
        scanf("%d", &keyvalue);
        insert(hashTable, keyvalue);
    }

    printf("\nHash Table :\n");
    display(hashTable);

    printf("\nEnter a key to search for : ");
    scanf("%d", &searchelement);
    
    struct SearchResult result = search(hashTable, searchelement);
    
    if (result.node) {
        printf("Key %d found in the Hash Table at index %d.\n", searchelement, result.index);
    } 
    else {
        printf("Key %d NOT Found in the Hash Table!!!\n", searchelement);
    }
}

/* OUTPUT

Enter the number of keys in the hash table : 9

Enter key 1 : 25
Enter key 2 : 16
Enter key 3 : 14
Enter key 4 : 35
Enter key 5 : 45
Enter key 6 : 24
Enter key 7 : 19
Enter key 8 : 36
Enter key 9 : 11

Hash Table :
Index 0 : NULL
Index 1 : 11 -> NULL
Index 2 : NULL
Index 3 : NULL
Index 4 : 24 -> 14 -> NULL
Index 5 : 45 -> 35 -> 25 -> NULL
Index 6 : 36 -> 16 -> NULL
Index 7 : NULL
Index 8 : NULL
Index 9 : 19 -> NULL

Enter a key to search for : 45
Key 45 found in the Hash Table at index 5.

Enter the number of keys in the hash table : 6

Enter key 1 : 10
Enter key 2 : 15
Enter key 3 : 20
Enter key 4 : 25
Enter key 5 : 30
Enter key 6 : 35

Hash Table :
Index 0 : 30 -> 20 -> 10 -> NULL
Index 1 : NULL
Index 2 : NULL
Index 3 : NULL
Index 4 : NULL
Index 5 : 35 -> 25 -> 15 -> NULL
Index 6 : NULL
Index 7 : NULL
Index 8 : NULL
Index 9 : NULL

Enter a key to search for : 3
Key 3 NOT Found in the Hash Table!!!

*/