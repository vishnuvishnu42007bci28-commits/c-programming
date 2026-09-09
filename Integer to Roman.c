#include <string.h>
#include <stdlib.h>

// Definition for mapping value to Roman numeral token
typedef struct {
    int value;
    const char* symbol;
} RomanMap;

char* intToRoman(int num) {
    // Array sorted from largest token value to smallest
    RomanMap mapping[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };

    // The longest Roman numeral string under 4000 is 15 characters long (e.g., 3888 is "MMMDCCCLXXXVIII")
    // Dynamically allocate 16 bytes (15 chars + 1 null terminator)
    char* result = (char*)malloc(16 * sizeof(char));
    result[0] = '\0'; // Initialize as empty string

    for (int i = 0; i < 13; i++) {
        while (num >= mapping[i].value) {
            strcat(result, mapping[i].symbol);
            num -= mapping[i].value;
        }
    }

    return result;
}
