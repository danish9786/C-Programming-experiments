#include <stdio.h>

int main(){
    float first, second, third, average;
    printf("Enter first number: ");
    scanf("%f", &first);
    printf("Enter second number: ");
    scanf("%f", &second);
    printf("Enter third number: ");
    scanf("%f", &third);
    average = (first + second + third) / 3;
    printf("Average of three numbers is: %f\n", average);
    return 0;
}