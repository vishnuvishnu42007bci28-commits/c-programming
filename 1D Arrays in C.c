#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n integers on the heap
    int *arr = (int*) malloc(n * sizeof(int));

    // Read array elements from stdin
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum of array elements
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print the total sum
    printf("%d\n", sum);

    // Deallocate dynamically allocated memory
    free(arr);

    return 0;
}
