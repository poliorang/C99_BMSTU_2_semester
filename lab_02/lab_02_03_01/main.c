// lab_02_03_01

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define SIZE 1024

#define ERROR_SIZE 1
#define ERROR_INCOR_SIM 2

int insert_new_elem(int a[], size_t *n, int b[], int count);
int scan(int a[], size_t n);
void print(int a[], size_t n);

int main(void)
{
    int a[SIZE];
    int count = 0;
    size_t n;
    int fib[2 * N];
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < 2 * N; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
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
    insert_new_elem(a, &n, fib, count);
    print(a, n);
    return EXIT_SUCCESS;
}

int insert_new_elem(int a[], size_t *n, int b[], int count)
{
    int flag = 0;
    for (size_t i = 0; i < *n; i++)
        if (a[i] % 3 == 0)
        {
            flag = 1;
            for (size_t j = *n; i < j; j--)
                a[j + 1] = a[j];
            a[i + 1] = b[count];
            count++;
            *n += 1;
            i++;
        }
    return flag;
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
