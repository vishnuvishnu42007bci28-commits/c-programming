#include <stdlib.h>
#include <string.h>

// Global constant mapping for the phone digits
const char* phone_map[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(const char* digits, int index, char* current, char** result, int* returnSize) {
    // Base case: If we reached the end of digits string
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    int digit_val = digits[index] - '0';
    const char* letters = phone_map[digit_val];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i]; // Place candidate letter
        current[index + 1] = '\0';   // Keep string null-terminated
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }

    // Compute maximum possible combinations to allocate enough array slots
    // 4 digits max, each digit has at most 4 letters -> max 4^4 = 256 paths
    int max_combinations = 1;
    for (int i = 0; i < len; i++) {
        int d = digits[i] - '0';
        max_combinations *= (d == 7 || d == 9) ? 4 : 3;
    }

    char** result = (char**)malloc(max_combinations * sizeof(char*));
    char* current = (char*)calloc(len + 1, sizeof(char));

    backtrack(digits, 0, current, result, returnSize);

    free(current);
    return result;
}
