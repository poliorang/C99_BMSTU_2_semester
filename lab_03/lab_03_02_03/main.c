// lab_03_02_03

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 512
#define N 10

#define SIZE_ERROR 1
#define INCORRECT_SIM_ERROR 2
#define NO_ELEM_ERROR 3

int find_num(int x, int num);
void delete_column(int a[][SIZE], size_t r, size_t *c, size_t j);
void find_and_delete_column(int a[][SIZE], size_t r, size_t *c, int num);
int scan_matrix(int a[][SIZE], size_t r, size_t c);
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
    int num;
    if (scanf("%d", &num) != 1 || num < 0 || num >= N)
    {
        printf("The number is set incorrectly");
        return INCORRECT_SIM_ERROR;
    }
    find_and_delete_column(a, r, &c, num);
    if (c == 0)
    {
        printf("All columns removed");
        return NO_ELEM_ERROR;
    }
    print_matrix(a, r, c);
    return EXIT_SUCCESS;
}

int find_num(int x, int num)
{
    if (x == 0 && num == 0)
        return 1;
    while (x > 0)
    {
        if (x % N == num)
            return 1;
        x /= N;
    }
    return 0;
}

void delete_column(int a[][SIZE], size_t r, size_t *c, size_t j)
{
    for (size_t i = 0; i < r; i++)
        for (size_t k = j; k < *c - 1; k++)
            a[i][k] = a[i][k + 1];
}

void find_and_delete_column(int a[][SIZE], size_t r, size_t *c, int num)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < *c; j++)
            if (find_num(abs(a[i][j]), num))
            {
                delete_column(a, r, c, j);
                (*c)--;
                j--;
            }
}

int scan_matrix(int a[][SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
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
