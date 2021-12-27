#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1024
#define INPUT_ERROR 1

int scan_arr(int a[], size_t n)
{
    for(size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return INPUT_ERROR;
    return EXIT_SUCCESS;
}

int is_prime(int x)
{
    if (x <= 1)
        return 0;
    for (int j = 2; j <= sqrt(x); j++)
        if (x % j == 0)
            return 0;
    return 1;
}

void insert_elem(int a[], size_t *n, size_t ind)
{
    for (size_t i = *n; i > ind; i--)
        a[i + 1] = a[i];
    a[ind + 1] = 0;
    (*n)++;
}

void print_arr(int a[], size_t n)
{
    for(size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    int a[SIZE];
    size_t n;
    if (scanf("%zu", &n) != 1)
    {
        printf("Incorrect input");
        return INPUT_ERROR;
    }
    if (n <= 0)
    {
        printf("Incorrect input");
        return INPUT_ERROR;
    }
    if (scan_arr(a, n))
    {
        printf("Incorrect input");
        return INPUT_ERROR;
    }
    for(size_t i = 0; i < n; i++)
        if (is_prime(a[i]))
            insert_elem(a, &n, i);
    print_arr(a, n);
    return EXIT_SUCCESS;
}
