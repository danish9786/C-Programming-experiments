#include <stdio.h>

// Recursive function to calculate factorial
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}

int main() {
    int num;
    long long result;

    // Input a number
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check for negative numbers
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        result = factorial(num);
        printf("Factorial of %d is: %lld\n", num, result);
    }

    return 0;
}
