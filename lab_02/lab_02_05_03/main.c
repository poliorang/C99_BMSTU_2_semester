// lab_02_05_03

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define SIZE 1024

#define ERROR_SIZE 1
#define ERROR_INCOR_SIM 2

int production(int *first, int *last);
int scan(int *first, int *last);

int main(void)
{
    int a[SIZE];
    size_t n;
    setbuf(stdout, NULL);
    printf("Enter the size of the array: ");
    if (scanf("%zu", &n) != 1)
    {
        printf("Incorrect dimension");
        return ERROR_SIZE;
    }
    if (n > N || n <= 1)
    {
        printf("Size of the array: [2, 10]");
        return ERROR_SIZE;
    }
    int *last = a + n;
    if (scan(a, last))
    {
        printf("Incorrect simbol");
        return ERROR_INCOR_SIM;
    }
    int res = production(a, last);
    printf("Minimum product of adjacent elements: %d", res);
    return EXIT_SUCCESS;
}

int scan(int *first, int *last)
{
    while (first < last)
        if (scanf("%d", first) == 1)
            first++;
        else
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int production(int *first, int *last)
{
    int *second = first++;
    int minim = *first * *second;
    while (first < last)
    {
        int com = *first * *second;
        if (com < minim)
            minim = com;
        first++;
        second++;
    }
    return minim;
}
