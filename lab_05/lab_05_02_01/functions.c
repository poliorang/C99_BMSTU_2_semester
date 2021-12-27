#include "functions.h"

int process(FILE *f, double mean, int *count)
{
    double num;
    while (fscanf(f, "%lf", &num) == 1)
    {
        if (num > mean)
            (*count)++;
    }
    return EXIT_SUCCESS;
}

int find_min_and_max(FILE *f, double *min_num, double *max_num)
{
    double num;
    size_t iter = 0;

    while (fscanf(f, "%lf", &num) == 1)
    {
        iter++;
        if (num > *max_num)
            *max_num = num;
        if (num < *min_num)
            *min_num = num;
    }
    if (!feof(f) || iter < 2)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
