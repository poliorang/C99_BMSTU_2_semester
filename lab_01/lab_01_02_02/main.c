/*
 lab_01_02_02
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    double s1, s2, s3;
    double p;
    scanf("%lf%lf", &xa, &ya);
    scanf("%lf%lf", &xb, &yb);
    scanf("%lf%lf", &xc, &yc);
    s1 = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    s2 = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    s3 = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    p = s1 + s2 + s3;
    printf("p = %.6lf", p);
    return EXIT_SUCCESS;
}
