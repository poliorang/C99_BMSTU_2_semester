// lab_03_06_03

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 512
#define N 10

#define SIZE_ERROR 1
#define INCORRECT_SIM_ERROR 2
#define NOT_SQUARE_MAT_ERROR 3

void insert_matrix(int a[][SIZE], size_t r);
void print_matrix(int a[][SIZE], size_t r);

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
    insert_matrix(a, r);
    print_matrix(a, r);
    return EXIT_SUCCESS;
}

void insert_matrix(int a[][SIZE], size_t r)
{
    int el = 1;
    for (size_t i = 0; i < r; i++)
        a[i][0] = el++;
    el--;
    for (size_t j = 0; j < r; j++)
        a[r - 1][j] = el++;
    el--;
    for (size_t i = r - 1; i; i--)
        a[i][r - 1] = el++;
    size_t k = 1;
    for (size_t n = 0; n < r / 2; n++)
    {
        for (size_t j = r - k; j > k - 1; j--)
            a[k - 1][j] = el++;
        for (size_t i = k; i < r - k; i++)
            a[i][k] = el++;
        k++;
        for (size_t j = k; j < r - k; j++)
            a[r - k][j] = el++;
        for (size_t i = r - k; i > k - 2; i--)
            a[i][r - k] = el++;
        el--;
    }
    if (r % 2 != 0)
        a[r / 2][r / 2] = r * r;
}

void print_matrix(int a[][SIZE], size_t r)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < r; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
