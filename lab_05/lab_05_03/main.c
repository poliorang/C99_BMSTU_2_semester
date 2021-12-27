//lab_05_03
#include <string.h>
#include <ctype.h>
#include "file_numbers.h"

#define ARG_ERROR -1
#define FILE_ERROR -2
#define INPUT_ERROR -3
#define EMPTY_FILE -4

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    FILE *f;
    if (argc != 3 && argc != 4)
        return ARG_ERROR;

    if (argc == 4)
    {
        f = fopen(argv[3], "wb");
        if (!strcmp(argv[1], "c"))
        {
            int rc = create_file(f, atoi(argv[2]));
            fclose(f);
            return rc;
        }
        else
        {
            fclose(f);
            return ARG_ERROR;
        }
    }

    if (argc == 3)
    {
        if (!strcmp(argv[1], "cr"))
        {
            f = fopen(argv[2], "w");
            printf("Enter numbers: ");
            create_bin(f);
            fclose(f);
        }

        f = fopen(argv[2], "rb+");

        if (f == NULL)
            return FILE_ERROR;

        long size = 0;
        if (file_size(f, &size))
            return FILE_ERROR;

        size /= sizeof (int);

        if (!size)
            return EMPTY_FILE;

        if (!strcmp(argv[1], "p"))
            output_numbers(f);
        else if (!strcmp(argv[1], "s"))
            sort(f);
        else
        {
            fclose(f);
            return ARG_ERROR;
        }
    }

    fclose(f);
    return EXIT_SUCCESS;
}
