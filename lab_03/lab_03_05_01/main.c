// lab_03_05_01

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 512
#define N 10

#define SIZE_ERROR 1
#define INCORRECT_SIM_ERROR 2
#define NO_MATCHING_ELEM 3

int sum_of_num(int x);
int form_array(int a[][SIZE], size_t r, size_t c, int b[]);
void shift_array(int b[], int count);
void insert_element(int a[][SIZE], size_t r, size_t c, int b[]);
int scan_matrix(int a[][SIZE], size_t *r, size_t *c);
void print_matrix(int a[][SIZE], size_t r, size_t c);

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
    int res_of_scan_mat = scan_matrix(a, &r, &c);
    if (res_of_scan_mat)
    {
        printf("Incorrect simbol in matrix");
        return res_of_scan_mat;
    }
    int count = form_array(a, r, c, b);
    if (!count)
    {
        printf("No matching elements in the matrix");
        return NO_MATCHING_ELEM;
    }
    shift_array(b, count);
    insert_element(a, r, c, b);
    print_matrix(a, r, c);
    return EXIT_SUCCESS;
}

int sum_of_num(int x)
{
    x = abs(x);
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int form_array(int a[][SIZE], size_t r, size_t c, int b[])
{
    size_t count = 0;
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (sum_of_num(a[i][j]) > N)
            {
                b[count] = a[i][j];
                count++;
            }
    return count;
}

void shift_array(int b[], int count)
{
    for (int i = 0; i < 3; i++)
        b[count + i] = b[i];
    for (int i = 3; i < count + 3; i++)
        b[i - 3] = b[i];
}

void insert_element(int a[][SIZE], size_t r, size_t c, int b[])
{
    int count = 0;
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (sum_of_num(a[i][j]) > 10)
            {
                a[i][j] = b[count];
                count++;
            }
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

int scan_matrix(int a[][SIZE], size_t *r, size_t *c)
{
    for (size_t i = 0; i < *r; i++)
        for (size_t j = 0; j < *c; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INCORRECT_SIM_ERROR;
    return EXIT_SUCCESS;
}
