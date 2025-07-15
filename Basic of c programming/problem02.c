#include<stdio.h>

int main(){
    float cel, far, input;
    printf("Enter a value of tempreture in celsius: ");
    scanf("%f",&input);
    far = (input * 9/5) + 32;
    cel = input;
    printf("tempreture in Fahrenheit is %f\n",far);
    // printf("tempreture in Celsius is %f\n",cel);
    return 0;
}