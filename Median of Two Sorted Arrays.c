#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to minimize the binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    int totalElements = m + n;
    int halfLen = (totalElements + 1) / 2;
    
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = halfLen - partitionX;
        
        // Handle edge cases where partitions are empty
        double maxLeftX = (partitionX == 0) ? -INFINITY : nums1[partitionX - 1];
        double minRightX = (partitionX == m) ? INFINITY : nums1[partitionX];
        
        double maxLeftY = (partitionY == 0) ? -INFINITY : nums2[partitionY - 1];
        double minRightY = (partitionY == n) ? INFINITY : nums2[partitionY];
        
        // Correct partition found
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if (totalElements % 2 != 0) {
                return MAX(maxLeftX, maxLeftY);
            }
            return (MAX(maxLeftX, maxLeftY) + MIN(minRightX, minRightY)) / 2.0;
        }
        // Too far right in nums1, move left
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        }
        // Too far left in nums1, move right
        else {
            low = partitionX + 1;
        }
    }
    
    return 0.0;
}
