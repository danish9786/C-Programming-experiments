#include <stdio.h>

int main() {
    int num, sum = 0;

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Find divisors and sum them
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check perfect number condition
    if (sum == num && num != 0)
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

    return 0;
}
