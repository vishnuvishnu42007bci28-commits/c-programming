#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d\n%d", &a, &b);
    
    // Array to store the string representations of 1 to 9
    const char* words[] = {
        "one", "two", "three", "four", "five", 
        "six", "seven", "eight", "nine"
    };

    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            // Index is (i - 1) because array is 0-indexed
            printf("%s\n", words[i - 1]);
        } else if (i % 2 == 0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }

    return 0;
}
