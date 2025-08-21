#include <stdio.h>

int main() {
    int n, i, j, isPrime;

    // Input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are:\n", n);

    // Loop through numbers from 2 to n
    for (i = 2; i <= n; i++) {
        isPrime = 1; // Assume the number is prime

        // Check divisibility
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0; // Not prime
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
