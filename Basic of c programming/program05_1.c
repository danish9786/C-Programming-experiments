// Swap two numbers using temporary variable
#include <stdio.h>
int main()
{
    int x, y, temp;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    temp = x;
    x = y;
    y = temp;

    printf("Now, the value of x and y is: %d, %d\n", x, y);

    return 0;
}