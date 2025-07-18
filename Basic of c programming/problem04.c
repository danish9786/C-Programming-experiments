#include <stdio.h>
#include <math.h>

int main()
{
    double principal, rate, time, SI, CI;

    printf("Enter principal amount: \n");
    scanf("%lf", &principal);
    printf("Enter rate of intrest: \n");
    scanf("%lf", &rate);
    printf("Enter time period of loan: \n");
    scanf("%lf", &time);

    SI = (principal * rate * time) / 100;
    CI = (principal * (pow((1 + (rate / 100)), time))) - principal;
    printf("\nSimple Intrest is: %lf", SI);
    printf("\nCompound intrest is: %lf", CI);

    return 0;
}