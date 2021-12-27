// lab_03_04_03

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 512
#define N 10

#define SIZE_ERROR 1
#define INCORRECT_SIM_ERROR 2
#define NOT_SQUARE_MAT_ERROR 3

void swap_columns(int a[][SIZE], size_t r);
int scan_matrix(int a[][SIZE], size_t *r, size_t *c);
void print_matrix(int a[][SIZE], size_t r, size_t c);

int main(void)
{
    int a[SIZE][SIZE];
    size_t r, c;

    if (scanf("%zu%zu", &r, &c) != 2)
    {
        printf("Incorrect parameters");
        return INCORRECT_SIM_ERROR;
    }
    if (r != c)
    {
        printf("Matrix is not square");
        return NOT_SQUARE_MAT_ERROR;
    }
    if (r <= 0 || r > N)
    {
        printf("Incorrect parameters size");
        return SIZE_ERROR;
    }
    int res_of_scan_mat = scan_matrix(a, &r, &r);
    if (res_of_scan_mat)
    {
        printf("Incorrect simbol in matrix");
        return res_of_scan_mat;
    }
    swap_columns(a, r);
    print_matrix(a, r, r);
    return EXIT_SUCCESS;
}

void swap_columns(int a[][SIZE], size_t r)
{
    int k = 0;
    for (size_t j = 0; j < r; (j++, r--))
    {
        for (size_t i = k; i < r; i++)
        {
            int x = a[i][j];
            a[i][j] = a[i][r - 1];
            a[i][r - 1] = x;
        }
        k++;
    }
}

int scan_matrix(int a[][SIZE], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r; i++)
        for (size_t j = 0; j < *c; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INCORRECT_SIM_ERROR;
    return EXIT_SUCCESS;
}

void print_matrix(int a[][SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
