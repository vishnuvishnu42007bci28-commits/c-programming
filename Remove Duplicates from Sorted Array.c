#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    // Pointer to track the position of the next unique element
    int insert_index = 1;

    for (int i = 1; i < numsSize; i++) {
        // If the current element is different from the previous one, it's unique
        if (nums[i] != nums[i - 1]) {
            nums[insert_index] = nums[i];
            insert_index++;
        }
    }

    return insert_index;
}
