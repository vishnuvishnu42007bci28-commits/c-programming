#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    // Array to store the last seen index of all 128 standard ASCII characters
    int last_seen[128];
    memset(last_seen, -1, sizeof(last_seen));
    
    int left = 0;
    int max_length = 0;
    int len = strlen(s);
    
    for (int right = 0; right < len; right++) {
        unsigned char current_char = s[right];
        
        // If the character was seen inside our current sliding window
        if (last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }
        
        // Record/Update the index of the character
        last_seen[current_char] = right;
        
        // Update the maximum length found so far
        max_length = max(max_length, right - left + 1);
    }
    
    return max_length;
}
