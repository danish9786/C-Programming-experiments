#include <stdio.h>

int main()
{
    int num, originalNum, reversedNum = 0, remainder;

    // Input from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Reverse the number
    while (num != 0)
    {
        remainder = num % 10;                       // Get last digit
        reversedNum = reversedNum * 10 + remainder; // Append digit
        num /= 10;                                  // Remove last digit
    }

    // Check palindrome condition
    if (originalNum == reversedNum)
        printf("Reverse of this number %d is same as original number.\n", originalNum);
    else
        printf("Reverse of this number %d is not same as original number.\n", originalNum);

    return 0;
}
