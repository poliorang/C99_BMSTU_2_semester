/*
 lab_01_05_00
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int my_power(int a, int n);

int main(void)
{
    int n, a;
    int result;
    if (scanf("%d", &a) != 1)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (scanf("%d", &n) != 1)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    if (n <= 0)
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    else
    {
        result = my_power(a, n);
        printf("%d", result);
        return EXIT_SUCCESS;
    }
}

int my_power(int a, int n)
{
    int res = 1;
    while (n != 0)
    {
        res *= a;
        n -= 1;
    }
    return res;
}
