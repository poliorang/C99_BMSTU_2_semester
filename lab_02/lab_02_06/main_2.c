// lab_02_06

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <inttypes.h>
#define N 10
#define SIZE 10000

#define ERROR_SIZE 1
#define ERROR_INCOR_SIM 2

int process_two(int a[], size_t n);
int scan(int *first, int *last);

int main(void)
{
    int a[SIZE];
    size_t n;
    setbuf(stdout, NULL);
    if (!scanf("%zu", &n))
    {
        printf("Incorrect size");
        return ERROR_SIZE;
    }
    int *last = a + n;
    if (scan(a, last))
    {
        printf("Incorrect simbol");
        return ERROR_INCOR_SIM;
    }
    struct timeval start, stop;
    int64_t elapsed_time;
    gettimeofday(&start, NULL);
    process_two(a, n);
    gettimeofday(&stop, NULL);
    elapsed_time = (stop.tv_sec - start.tv_sec) * 1000000LL + (stop.tv_usec - start.tv_usec);
    printf("%" PRId64 "\n", elapsed_time);
    return EXIT_SUCCESS;
}

int process_two(int a[], size_t n)
{
    int minim = a[0] * a[1];
    for (size_t i = 0; i < (n - 1); i++)
    {
        if (*(a + i) * *(a + i + 1) < minim)
            minim = *(a + i) * *(a + i + 1);
    }
    return minim;
}

int scan(int *first, int *last)
{
    while (first < last)
    {
        if (scanf("%d", first) == 1)
            first++;
        else
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
