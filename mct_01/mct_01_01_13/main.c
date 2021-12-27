#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1024

void scan_arr(double a[], size_t *n)
{
    double x;
    size_t i = 0;
    while (scanf("%lf", &x) == 1 && (x >= 0.0))
    {
        a[i] = x;
        i++;
    }
    *n = i;
}

double g(double a[], size_t n)
{
    if (n == 0)
        return 0.0;
    double res = sqrt(a[0]);
    for (size_t i = 1; i < n; i ++)
        res = sqrt(res + a[i]);
    return res;
}

int main(void)
{
    double a[SIZE];
    size_t n = 0;
    scan_arr(a, &n);
    printf("%lf", g(a, n));
    return EXIT_SUCCESS;
}
