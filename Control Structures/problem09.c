#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    printf("Entre first number : ");
    scanf("%d", &a);
    printf("\nEntre secand number : ");
    scanf("%d", &b);

    if (a > b)
    {
        printf("The first number %d is grater\n", a);
    }
    else if (a < b)
    {
        printf("The secand number %d is grater\n", b);
    }
    else
    {
        printf("both numbers %d and %d are equal\n", a, b);
    }
}