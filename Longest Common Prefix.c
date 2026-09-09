#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    // If the input array is empty, return an empty string
    if (strsSize == 0) {
        char* empty = (char*)malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    // Use the first string as the baseline for comparison
    char* first_str = strs[0];
    int i = 0;

    // Iterate through each character of the first string
    while (first_str[i] != '\0') {
        char current_char = first_str[i];

        // Check this character against all other strings at the same index
        for (int j = 1; j < strsSize; j++) {
            // If the current string is shorter or the character doesn't match
            if (strs[j][i] == '\0' || strs[j][i] != current_char) {
                // Null-terminate the first string at the mismatch index
                // to turn it into the longest common prefix
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, first_str, i);
                result[i] = '\0';
                return result;
            }
        }
        i++;
    }

    // If the entire first string is the common prefix
    char* result = (char*)malloc((i + 1) * sizeof(char));
    strcpy(result, first_str);
    return result;
}
