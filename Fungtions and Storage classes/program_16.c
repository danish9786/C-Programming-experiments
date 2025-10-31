#include<stdio.h>

//Write a C program that uses a function with a return value to add two numbers. 

int addnum(int x, int y){
    return x + y ;
}

int main(){
    int num1, num2, num3;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    num3 = addnum(num1,num2);
    printf("Sum of the number %d and %d is %d", num1, num2, num3);

    return 0;
}