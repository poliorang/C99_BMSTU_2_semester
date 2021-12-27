//mct_02_02_11
#include "products.h"

#define ARG_ERROR -1
#define FILE_ERROR -2
#define EMPTY_OR_INVALID_FILE -3
#define AVG_ERROR -4

int main(int argc, char *argv[])
{
    FILE *f;
    long size = 0, count = 0;
    double avg = 0;

    if (argc != 3 && argc != 2)
        return ARG_ERROR;

    //secondary function
    if (argc == 3 && !strcmp(argv[1], "re"))
    {
        f = fopen(argv[2], "rb");
        read_bin(f);
        fclose(f);
        EXIT_SUCCESS;
    }
    //secondary function
    if (argc == 3 && !strcmp(argv[1], "cr"))
    {
        f = fopen(argv[2], "wb");
        create_bin(f);
        fclose(f);
        EXIT_SUCCESS;
    }

    f = fopen(argv[1], "rb+");

    if (f == NULL)
    {
        fclose(f);
        return FILE_ERROR;
    }

    avg = average(f, &count);
    if (avg < 0)
    {
        fclose(f);
        return AVG_ERROR;
    }

    if (file_size(f, &size))
    {
        fclose(f);
        return FILE_ERROR;
    }

    if (!count || size % count != 0)
    {
        fclose(f);
        return EMPTY_OR_INVALID_FILE;
    }

    if (delete_on_average(f, avg, argv[1]))
    {
        fclose(f);
        return AVG_ERROR;
    }

    fclose(f);
    return EXIT_SUCCESS;
}
