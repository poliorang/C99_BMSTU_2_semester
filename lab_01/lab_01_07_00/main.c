/*
 lab_01_07_00
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double summ(double x, double eps);

int main(void)
{
    double x;
    double eps;
    double f, s;
    double abs_pre, relative_pre;

    if ((scanf("%lf", &x) != 1) || (scanf("%lf", &eps) != 1))
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if ((eps > 0) && (eps <= 1))
    {
        f = exp(x);
        s = summ(x, eps);
        abs_pre = fabs(f - s);
        relative_pre = abs_pre / fabs(f);
        printf("%.6lf\n", s);
        printf("%.6lf\n", f);
        printf("%.6lf\n", abs_pre);
        printf("%.6lf\n", relative_pre);

        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
}

double summ(double x, double eps)
{
    double next = x;
    double count = 1;
    double s = 1;
    while (fabs(next) >= eps)
    {
        s += next;
        next *= x;
        count++;
        next = next / count;
    }
    return s;
}
