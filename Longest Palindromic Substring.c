#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to expand outward around a center point
// Returns the length of the found palindromic substring
int expandAroundCenter(const char* s, int len, int left, int right) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return length calculated from the valid bounds
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (s == NULL || *s == '\0') {
        char* empty = (char*)malloc(sizeof(char));
        *empty = '\0';
        return empty;
    }

    int len = strlen(s);
    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < len; i++) {
        // Case 1: Odd-length palindromes (e.g., "aba")
        int len1 = expandAroundCenter(s, len, i, i);
        // Case 2: Even-length palindromes (e.g., "bb")
        int len2 = expandAroundCenter(s, len, i, i + 1);

        // Find the maximum of both cases
        int currentMax = (len1 > len2) ? len1 : len2;

        // If a strictly longer palindrome is found, update tracking pointers
        if (currentMax > maxLen) {
            maxLen = currentMax;
            start = i - (currentMax - 1) / 2;
        }
    }

    // Allocate memory for the result substring (+1 for null-terminator)
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0'; // Explicitly add null-terminator

    return result;
}
