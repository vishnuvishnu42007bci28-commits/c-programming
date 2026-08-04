#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    
    // Extract each digit using modulo (%) and integer division (/)
    while (n > 0) {
        sum += n % 10; // Get the last digit and add it to sum
        n /= 10;       // Remove the last digit
    }
    
    printf("%d\n", sum);
    
    return 0;
}
