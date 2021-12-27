// lab_02_02_01

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define SIZE 1024

#define ERROR_SIZE 1
#define ERROR_INCOR_SIM 2
#define ERROR_NO_PRIME 3

int scan(int a[], size_t n);
int is_prime(int x);
void print(int a[], size_t n);

int main(void)
{
    int a[SIZE];
    int b[SIZE];
    int j = 0;
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
    for (size_t i = 0; i < n; i++)
        if (!is_prime(a[i]))
        {
            b[j] = a[i];
            j++;
        }
    if (j == 0)
    {
        printf("Prime elements are missing");
        return ERROR_NO_PRIME;
    }
    else
    {
        printf("Simple elements: ");
        print(b, j);
        return EXIT_SUCCESS;
    }
}

int is_prime(int x)
{
    if (x <= 1 || (x % 2 == 0 && x != 2))
        return EXIT_FAILURE;
    for (int i = 2; i < sqrt(x) + 1; i ++)
        if (x % i == 0 && x != 2)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int scan(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void print(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
}
