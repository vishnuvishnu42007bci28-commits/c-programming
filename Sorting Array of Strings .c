#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 1. Lexicographically non-decreasing order (A to Z)
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Lexicographically non-increasing order (Z to A)
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper function to count distinct characters in a string
int count_distinct_chars(const char* str) {
    int hash[26] = {0};
    int distinct_count = 0;
    while (*str) {
        int index = *str - 'a';
        if (hash[index] == 0) {
            hash[index] = 1;
            distinct_count++;
        }
        str++;
    }
    return distinct_count;
}

// 3. Sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = count_distinct_chars(a);
    int count_b = count_distinct_chars(b);
    
    if (count_a == count_b) {
        return strcmp(a, b); // Tie-breaker: Lexicographically smaller first
    }
    return count_a - count_b;
}

// 4. Sort by string length
int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    if (len_a == len_b) {
        return strcmp(a, b); // Tie-breaker: Lexicographically smaller first
    }
    return len_a - len_b;
}

// Custom sorting implementation using Bubble Sort strategy
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            // If cmp_func returns a value greater than 0, elements are out of order
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


  

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
