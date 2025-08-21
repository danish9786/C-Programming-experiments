#include <stdio.h>

int main()
{
    int num1, num2;
    char op;

    // Input two numbers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Input operator
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &op); // space before %c to ignore whitespace

    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        break;

    case '-':
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        break;

    case '*':
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        break;

    case '/':
        if (num2 != 0)
            printf("%d / %d = %d\n", num1, num2, num1 / num2);
        else
            printf("Error! Division by zero is not allowed.\n");
        break;

    case '%':
        if (num2 != 0)
            printf("%d %% %d = %d\n", num1, num2, num1 % num2);
        else
            printf("Error! Modulus by zero is not allowed.\n");
        break;

    default:
        printf("Invalid operator!\n");
    }

    return 0;
}
