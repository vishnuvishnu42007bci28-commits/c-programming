#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    
    int *arr = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach to reverse the array in-place
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }

    // Print the reversed array
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
