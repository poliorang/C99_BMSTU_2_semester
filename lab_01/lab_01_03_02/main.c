/*
 lab_01_03_02
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double r1, r2, r3;
    double r;
    printf("First Resistance \n");
    scanf("%lf", &r1);
    printf("Second Resistance \n");
    scanf("%lf", &r2);
    printf("Third Resistance \n");
    scanf("%lf", &r3);
    r = (r1 * r2 * r3) / (r2 * r3 + r1 * r3 + r1 * r2);
    printf("Total resistance = %.6lf", r);
    return EXIT_SUCCESS;
}
