#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Lexicographically non-decreasing order
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Lexicographically non-increasing order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper function to count unique characters in a string
int count_distinct_characters(const char* s) {
    int count[26] = {0};
    int distinct = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 0) {
            count[s[i] - 'a'] = 1;
            distinct++;
        }
    }
    return distinct;
}

// 3. Non-decreasing order of distinct characters count
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = count_distinct_characters(a);
    int count_b = count_distinct_characters(b);
    
    if (count_a != count_b) {
        return count_a - count_b;
    }
    return strcmp(a, b); // Tie-breaker: lexicographically smaller first
}

// 4. Non-decreasing order of string length
int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    if (len_a != len_b) {
        return len_a - len_b;
    }
    return strcmp(a, b); // Tie-breaker: lexicographically smaller first
}

// Custom Bubble Sort function accepting a comparator function pointer
void string_sort(const char** arr, const int cnt, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                const char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
