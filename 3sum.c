#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the array first
    qsort(nums, numsSize, sizeof(int), compare);
    
    int capacity = 16; // Initial capacity for the result array
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize - 2; i++) {
        // Optimization: If the smallest element is greater than 0, sum 0 is impossible
        if (nums[i] > 0) break;
        
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Resize result array if it exceeds current capacity
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                // Allocate space for the current triplet
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                // Skip duplicate values for the second and third elements
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++; // Sum is too small, move to a larger number
            } else {
                right--; // Sum is too large, move to a smaller number
            }
        }
    }
    
    return result;
}
