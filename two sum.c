#include <stdlib.h>

// Definition for a hash map entry
typedef struct {
    int key;
    int value;
    int is_occupied;
} HashEntry;

// Simple hash function using modulo
int hash(int key, int capacity) {
    int h = key % capacity;
    if (h < 0) {
        h += capacity; // Handle negative keys
    }
    return h;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate space for the result
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Use a hash table size roughly twice the size of the array to reduce collisions
    int capacity = numsSize * 2;
    HashEntry* hashTable = (HashEntry*)calloc(capacity, sizeof(HashEntry));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Search for the complement in the hash table
        int h = hash(complement, capacity);
        while (hashTable[h].is_occupied) {
            if (hashTable[h].key == complement) {
                // Found the complement! Fill the result and clean up memory
                result[0] = hashTable[h].value;
                result[1] = i;
                free(hashTable);
                return result;
            }
            // Linear probing
            h = (h + 1) % capacity;
        }

        // Complement not found, insert current number into the hash table
        h = hash(nums[i], capacity);
        while (hashTable[h].is_occupied) {
            h = (h + 1) % capacity;
        }
        hashTable[h].key = nums[i];
        hashTable[h].value = i;
        hashTable[h].is_occupied = 1;
    }

    // Free the table memory if no solution is found (though the problem guarantees one)
    free(hashTable);
    return NULL;
}
