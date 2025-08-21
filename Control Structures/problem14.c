#include <stdio.h>

// Function to compute factorial of a digit
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num, originalNum, remainder, sum = 0;

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Compute sum of factorial of digits
    while (num != 0) {
        remainder = num % 10;
        sum += factorial(remainder);
        num /= 10;
    }

    // Check Strong number condition
    if (sum == originalNum)
        printf("%d is a Strong number.\n", originalNum);
    else
        printf("%d is not a Strong number.\n", originalNum);

    return 0;
}
