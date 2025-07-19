#include<stdio.h>

int main(){
    float redii, a, l, b, pi;
    pi = 3.14;
    printf("Enter the rediius of circle: ");
    scanf("%f",&redii);
    printf("Enter the side of square: ");
    scanf("%f",&a);
    printf("Enter the length of rectangle: ");
    scanf("%f",&l);
    printf("Enter the breath of ractangle: ");
    scanf("%f",&b);

    float ar_circle = (pi*redii*redii);
    float para_circle =(2*pi*redii);
    float ar_square = (a*a);
    float para_square = (4*a);
    float ar_rectangle = (l*b);
    float para_rectangle = (2*(l+b));

    printf("area of the circle is: %f\n",ar_circle);
    printf("circumference of the circle is:%f\n",para_circle);
    printf("area of the square is: %f\n",ar_square);
    printf("parameter of the square is: %f\n",para_square);
    printf("area of the rectangle is: %f\n",ar_rectangle);
    printf("parameter of the rectangle is: %f\n",para_rectangle);

    return 0;
}