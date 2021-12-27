// lab_02_07
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define SIZE 100000

#define ERROR_SIZE 1
#define ERROR_MORE_ELEM 100

void insertion_sort(double a[], size_t n);
int scan(double a[]);
void print(double a[], size_t n);

int main(void)
{
    double a[SIZE];
    setbuf(stdout, NULL);
    int res = scan(a);
    if (res == 0)
    {
        printf("No item entered");
        return ERROR_SIZE;
    }
    insertion_sort(a, res);
    printf("Sorted array: ");
    print(a, res);
    return EXIT_SUCCESS;
}

void insertion_sort(double a[], size_t n)
{
    double el;
    int pos;
    for (size_t i = 1; i < n; i++)
    {
        el = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos] > el)
        {
            a[pos + 1] = a[pos];
            pos -= 1;
        }
        a[pos + 1] = el;
    }
}

int scan(double a[])
{
    size_t i = 0;
    while (i < SIZE)
        if (scanf("%lf", &a[i]) == 1)
            i++;
        else
            return i;
    return i;
}

void print(double a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%.6lf ", a[i]);
}
