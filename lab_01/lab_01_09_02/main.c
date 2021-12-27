/*
 lab_01_09_03
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS (1e-8)

double square_root(double x, double n);

int main(void)
{
    double n = 0;
    double x;
    double g = 0;

    if (scanf("%lf", &x) != 1)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (x < 0)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    while (x >= 0)
    {
        n++;
        g += square_root(x, n);
        if (scanf("%lf", &x) != 1)
        {
            printf("Input error");
            return EXIT_FAILURE;
        }
    }
    g = g / n;
    if (g > EPS)
    {
        printf("%.6lf", g);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
}

double square_root(double x, double n)
{
    x = sqrt(n + x);
    return x;
}
