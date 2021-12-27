//lab_05_04_01
#include "students.h"

#define ARG_ERROR 53
#define FILE_ERROR -2
#define FUNC_ERROR -3
#define EMPTY_OR_INVALID_FILE -4


int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 5)
        return ARG_ERROR;

    if (strcmp(argv[1], "re") && strcmp(argv[1], "cr") && strcmp(argv[1], "fb")
        && strcmp(argv[1], "sb") && strcmp(argv[1], "db"))
        return ARG_ERROR;

    FILE *f, *fin, *fout;
    long size;

    if (argc == 3 && !strcmp(argv[1], "re"))
    {
        f = fopen(argv[2], "rb");
        if (f == NULL)
            return FILE_ERROR;

        if (file_size(f, &size))
            return FILE_ERROR;

        if (!size || size % (sizeof (student_t)) != 0)
        {
            fclose(f);
            return EMPTY_OR_INVALID_FILE;
        }
        read_bin(f);
        fclose(f);
    }

    if (argc == 3 && !strcmp(argv[1], "cr"))
    {
        f = fopen(argv[2], "wb");
        create_bin(f);
        fclose(f);
    }

    if (argc == 3 && !strcmp(argv[1], "sb"))
    {
        f = fopen(argv[2], "rb+");
        if (f == NULL)
            return FILE_ERROR;

        if (file_size(f, &size))
            return FILE_ERROR;

        if (!size || size % (sizeof (student_t)) != 0)
        {
            fclose(f);
            return EMPTY_OR_INVALID_FILE;
        }

        if (sort(f))
            return FUNC_ERROR;

        fclose(f);
    }

    if (argc == 3 && !strcmp(argv[1], "db"))
    {
        f = fopen(argv[2], "rb+");
        if (f == NULL)
            return FILE_ERROR;

        if (file_size(f, &size))
            return FILE_ERROR;

        if (!size || size % (sizeof (student_t)) != 0)
        {
            fclose(f);
            return EMPTY_OR_INVALID_FILE;
        }

        long count = size / (sizeof (student_t));

        if (delete_on_average(f, &count, argv[2]))
            return FUNC_ERROR;
        fclose(f);
    }

    if (!strcmp(argv[1], "fb"))
    {
        if (argc != 5)
            return ARG_ERROR;
        fin = fopen(argv[2], "rb");
        fout = fopen(argv[3], "wb");
        if (fin == NULL || fout == NULL)
            return FILE_ERROR;

        if (file_size(fin, &size))
            return FILE_ERROR;

        if (!size || size % (sizeof (student_t)) != 0)
        {
            fclose(fin);
            fclose(fout);
            return EMPTY_OR_INVALID_FILE;
        }

        long count = 0;

        output_substr(fin, fout, argv[4], &count);    

        if (file_size(fout, &size))
            return FILE_ERROR;

        if (!count || size % (sizeof (student_t)) != 0)
        {
            fclose(fin);
            fclose(fout);
            return EMPTY_OR_INVALID_FILE;
        }
        fclose(fin);
        fclose(fout);
    }
    return EXIT_SUCCESS;
}


