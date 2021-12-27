/*
 lab_01_06_00
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-8

int type_of_triangle(double xa, double ya, double xb, double yb, double xc, double yc);
int nondegeneracy(double xa, double ya, double xb, double yb, double xc, double yc);

int main(void)
{
    setbuf(stdout, NULL);
    double xa, ya, xb, yb, xc, yc;
    int res;
    if (scanf("%lf%lf", &xa, &ya) != 2)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (scanf("%lf%lf", &xb, &yb) != 2)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (scanf("%lf%lf", &xc, &yc) != 2)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (nondegeneracy(xa, ya, xb, yb, xc, yc) != 1)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (((fabs(xa - xb) < EPS && fabs(ya - yb) < EPS)
        || (fabs(xa - xc) < EPS && fabs(ya - yc) < EPS)
        || (fabs(xb - xc) < EPS && fabs(yb - yc) < EPS)))
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    else
    {
        res = type_of_triangle(xa, ya, xb, yb, xc, yc);
        printf("%d", res);
        return EXIT_SUCCESS;
    }
}
int type_of_triangle(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double first_res, second_res, third_res;
    first_res = (xb - xa) * (xc - xa) + (yb - ya) * (yc - ya);
    second_res = (xa - xb) * (xc - xb) + (ya - yb) * (yc - yb);
    third_res = (xa - xc) * (xb - xc) + (ya - yc) * (yb - yc);
    if (fabs(first_res) <= EPS || fabs(second_res) <= EPS || fabs(third_res) <= EPS)
        return 1;
    else if ((first_res < 0) || (second_res < 0) || (third_res < 0))
        return 2;
    else
        return 0;
}

int nondegeneracy(double xa, double ya, double xb, double yb, double xc, double yc)
{
    if (fabs((xc - xa) * (yb - ya) - (yc - ya) * (xb - xa)) <= EPS)
        return 0;
    else
        return 1;
}
