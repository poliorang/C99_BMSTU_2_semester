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

int process_zero(int *first, int *second, int *last);
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
    int *penult = a + n - 1;
    int *second = a + 1;
    if (scan(a, last))
    {
        printf("Incorrect simbol");
        return ERROR_INCOR_SIM;
    }
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time;
    gettimeofday(&tv_start, NULL);
    process_zero(a, second, penult);
    gettimeofday(&tv_stop, NULL);
    elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    printf("%" PRId64 "\n", elapsed_time);
    return EXIT_SUCCESS;
}

int process_zero(int *first, int *second, int *last)
{
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
