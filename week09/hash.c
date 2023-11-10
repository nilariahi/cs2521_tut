#include <stdio.h>

// Note: this file won't compile unless threeSum is commented out
// because the HashTable ADT is missing

// Q1
#define HT_SIZE 42
int hash(char *key, int N) {
    // the main deficiency of this function was that
    // anagrams hash to the same value
    // to fix this, we incorporate the position of each
    // char into the hash value
    int h = 0;
    char *c;
    int i = 0;
    for (c = key; *c != '\0'; c++) {
        h = h + (*c * i);
    }
    return h % N;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        printf("hash(%s) = %d\n", argv[i], hash(argv[i], HT_SIZE));
    }
}

// Q5
bool threeSum(int arr[], int size, int sum) {
    HashTable ht = HashTableNew();

    // for each element in arr check if we can sum it with any 
    // 2 items we've previously seen in arr to get the target sum
    for (int i = 0; i < size; i++) {
        if (HashTableContains(ht, sum - arr[i])) {
            HashTableFree(ht);
            return true;
        }

        for (int j = 0; j < i; j++) {
            HashTableInsert(ht, arr[j] + arr[i], 0);
        }
    }

    HashTableFree(ht);
    return false;
}

// HashTable operations:
HashTable HashTableNew(void);
void HashTableFree(HashTable ht);
void HashTableInsert(HashTable ht, int key, int value);
bool HashTableContains(HashTable ht, int key);
int HashTableGet(HashTable ht, int key);
void HashTableDelete(HashTable ht, int key);
int HashTableSize(HashTable ht);
