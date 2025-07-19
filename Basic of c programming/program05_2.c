// Swap two numbers without using temporary variable
#include <stdio.h>
int main()
{
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    x = x + y;
    y = x - y;
    x = x - y;

    printf("Now, the value of x and y is: %d, %d\n", x, y);

    return 0;
}