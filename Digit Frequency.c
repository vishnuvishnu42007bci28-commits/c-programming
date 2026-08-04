#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];
    scanf("%s", s);

    // Frequency array initialized to 0 for digits 0-9
    int freq[10] = {0};

    // Iterate through the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            // Convert character digit '0'-'9' to integer index 0-9
            freq[s[i] - '0']++;
        }
    }

    // Print frequencies of digits from 0 to 9 separated by a space
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");

    return 0;
}
