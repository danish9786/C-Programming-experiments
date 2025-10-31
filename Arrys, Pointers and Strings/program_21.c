// Write a C program to find both the largest and smallest numbers in a list of integers.
#include <stdio.h>

int main()
{
    int g = 0, s;
    int list[10] = {23, 4, 67, 55, 2, 100, 33, 11, 67, 44};
    //to find gratest number
    for (int i = 0; i < 10; i++)
    {
        if (g < list[i])
        {
            g = list[i];
        }
    }
    s = g;
    // to find smallest number
    for (int i = 0; i < 10; i++)
    {
        if (s > list[i])
        {
            s = list[i];
        }
    }
    printf("Gratest number in the list is: %d\n", g);
    printf("Smallest number in the list is: %d", s);
    return 0;
}