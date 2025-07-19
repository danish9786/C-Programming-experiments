// Find the sum of individual digits of a positive number

#include <stdio.h>

int main(){
    int num, sum = 0, digit;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    while (num > 0){
        digit = num % 10;
        sum += digit;
        num /= 10;
    }
    printf("The sum of the digits is: %d\n", sum);
    return 0;
}