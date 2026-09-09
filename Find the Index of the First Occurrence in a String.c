#include <string.h>

int strStr(char* haystack, char* needle) {
    // strstr returns a pointer to the first occurrence of needle in haystack
    char* pointer = strstr(haystack, needle);
    
    // If needle is not found, return -1
    if (pointer == NULL) {
        return -1;
    }
    
    // Pointer arithmetic gives the starting index
    return pointer - haystack;
}

