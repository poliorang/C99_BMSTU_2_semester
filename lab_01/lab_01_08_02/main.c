/*
 lab_01_08_03
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#define CONSTANT_ONE (pow(2, 31))
#define CONSTANT_SECOND (pow(2, 32))

uint32_t shift(uint32_t a, int n);

int main(void)
{
    uint32_t a;
    int n;
    if ((scanf("%" SCNu32, &a) != 1))
    {
        printf("Error: invalid character entered");
        return EXIT_FAILURE;
    }
    if ((scanf("%d", &n) != 1))
    {
        printf("Error: invalid character entered");
        return EXIT_FAILURE;
    }
    if (n < 0)
    {
        printf("Error: shift is a positive number");
        return EXIT_FAILURE;
    }
    if (a > CONSTANT_SECOND)
    {
        printf("Error: too big number");
        return EXIT_FAILURE;
    }
    else
    {
        a = shift(a, n);
        int i = 32;
        printf("Result: ");
        while (i != 0)
        {
            if (a >= CONSTANT_ONE)
                printf("1");
            else
                printf("0");
            a <<= 1;
            i--;
        }
        return EXIT_SUCCESS;
    }
}

uint32_t shift(uint32_t a, int n)
{
    while (n > 0)
    {
        if (a >= CONSTANT_ONE)
        {
            a = (a << 1) + 1;
        }
        else
        {
            a <<= 1;
        }
        n--;
    }
    return a;
}
