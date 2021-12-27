//lab_05_02_02
#include "functions.h"
#include <float.h>

#define DBL_MAX __DBL_MAX__
#define DBL_MIN __DBL_MIN__

#define ARG_ERROR -1
#define FILE_ERROR -2
#define INPUT_ERROR -3

int main(int argc, char *argv[])
{
    FILE *f;
    double max_num = DBL_MIN, min_num = DBL_MAX;
    double mean;
    int count = 0;

    if (argc != 2)
    {
        printf("Invalid number of arguments");
        return ARG_ERROR;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("Invalid file");
        return FILE_ERROR;
    }

    if (find_min_and_max(f, &min_num, &max_num))
    {
        printf("Invalid input");
        return INPUT_ERROR;
    }

    mean = (min_num + max_num) / 2.0;

    fseek(f, 0L, SEEK_SET);
    process(f, mean, &count);

    fclose(f);

    printf("%d", count);
}
