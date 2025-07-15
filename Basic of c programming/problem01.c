#include <stdio.h>

int main()
{
    char input;
    int value;
    printf("Enter a key on keyboard:");
    scanf("%c", &input);

    value = (int)input;

    printf("ASCII value of %c is: %d", input, value);
    return 0;
}