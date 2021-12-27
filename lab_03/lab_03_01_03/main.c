// lab_03_01_03

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 512
#define N 10

#define SIZE_ERROR 1
#define ONE_ELEM_ERROR 2
#define INCORRECT_SIM_ERROR 3

int scan_matrix(int a[][SIZE], size_t r, size_t c);
void is_mono_sequence(int a[][SIZE], size_t r, size_t c, int b[]);
void print_array(int a[], size_t r);

int main(void)
{
    int a[SIZE][SIZE];
    int b[SIZE];
    size_t r, c;
    if (scanf("%zu%zu", &r, &c) != 2)
    {
        printf("Incorrect parameters");
        return INCORRECT_SIM_ERROR;
    }
    if (r <= 0 || r > N || c <= 0 || c > N)
    {
        printf("Incorrect parameters size");
        return SIZE_ERROR;
    }
    int res_of_scan = scan_matrix(a, r, c);
    if (res_of_scan)
    {
        printf("Incorrect simbol in matrix");
        return res_of_scan;
    }
    is_mono_sequence(a, r, c, b);
    print_array(b, r);
    return EXIT_SUCCESS;
}

int scan_matrix(int a[][SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INCORRECT_SIM_ERROR;
    return EXIT_SUCCESS;
}

void is_mono_sequence(int a[][SIZE], size_t r, size_t c, int b[])
{
    for (size_t i = 0; i < r; i++)
        if (c == 1)
            b[i] = 0;
        else
        {
            b[i] = 1;
            for (size_t j = 1; j < c - 1; j++)
                if (((a[i][j] - a[i][j - 1]) * (a[i][j + 1] - a[i][j])) < 0)
                    b[i] = 0;
        }
}

void print_array(int b[], size_t r)
{
    for (size_t i = 0; i < r; i++)
        printf("%d ", b[i]);
}
