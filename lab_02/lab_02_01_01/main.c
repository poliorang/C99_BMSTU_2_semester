// lab_02_01_01

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1024
#define N 10

#define ERROR_SIZE 1
#define ERROR_INCOR_SIM 2
#define ERROR_NO_ODD 3

int scan(int a[], size_t n);
int prod_of_odd(int a[], size_t n);

int main(void)
{
    int a[SIZE];
    size_t n;
    setbuf(stdout, NULL);
    printf("Enter the size of the array: ");
    if (scanf("%zu", &n) != 1)
    {
        printf("Incorrect size");
        return ERROR_SIZE;
    }
    if (n > N || n <= 0)
    {
        printf("Size of the array: [1, 10]");
        return ERROR_SIZE;
    }
    if (scan(a, n))
    {
        printf("Incorrect simbol");
        return ERROR_INCOR_SIM;
    }
    if (prod_of_odd(a, n))
    {
        printf("Product of odd elements: %d", prod_of_odd(a, n));
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Оdd elements are missing");
        return ERROR_NO_ODD;
    }
}

int scan(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int prod_of_odd(int a[], size_t n)
{
    int odd = 1;
    int flag = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] % 2 != 0)
        {
            flag = 1;
            odd *= a[i];
        }
    if (flag == 0)
        odd = 0;
    return odd;
}
