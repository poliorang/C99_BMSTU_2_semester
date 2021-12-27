// lab_03_03_03

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 512
#define N 10

#define SIZE_ERROR 1
#define INCORRECT_SIM_ERROR 2

int is_min_elem(int a[], size_t r);
void swap(int a[], int b[], size_t r);
void bubble_sort_rows(int a[][SIZE], size_t r, size_t c);
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
    if (r <= 0 || r > N || c <= 0 || c > N)
    {
        printf("Incorrect parameters size");
        return SIZE_ERROR;
    }
    int res_of_scan_mat = scan_matrix(a, &r, &c);
    if (res_of_scan_mat)
    {
        printf("Incorrect simbol in matrix");
        return res_of_scan_mat;
    }
    bubble_sort_rows(a, r, c);
    print_matrix(a, r, c);
    return EXIT_SUCCESS;
}

int is_min_elem(int a[], size_t r)
{
    int minim = a[0];
    for (size_t i = 1; i < r; i++)
        if (a[i] < minim)
            minim = a[i];
    return minim;
}

void swap(int a[], int b[], size_t r)
{
    for (size_t i = 0; i < r; i++)
    {
        int x = a[i];
        a[i] = b[i];
        b[i] = x;
    }
}

void bubble_sort_rows(int a[][SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = r - 1; j > i; j--)
            if (is_min_elem(a[j - 1], c) < is_min_elem(a[j], c))
                swap(a[j], a[j - 1], c);
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
