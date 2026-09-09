int removeElement(int* nums, int numsSize, int val) {
    int insert_index = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // If the current element is not the target value, keep it
        if (nums[i] != val) {
            nums[insert_index] = nums[i];
            insert_index++;
        }
    }
    
    return insert_index;
}
