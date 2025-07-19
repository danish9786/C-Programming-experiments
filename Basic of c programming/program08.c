// Find the roots of a Quadratic Equation.
#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c,D,x0,x1;
    printf("For the Quadratic Equation ax^2 + bx + c = 0\n");
    printf("Entre the valu of a for your Quadratic Equation: ");
    scanf("%f",&a);
    printf("Enter the value of b for your Quadratic Equation: ");
    scanf("%f",&b);
    printf("Enter the value of c for your Quadratic Equation: ");
    scanf("%f",&c);
    
    D = pow(((b*b)-(4*a*c)),0.5);
    x0 = ((-b)+D)/(2*a);
    x1 = ((-b)-D)/(2*a);

    printf("the roots of your Quadratic Equation is: %f, %f",x0,x1);
    return 0;
}