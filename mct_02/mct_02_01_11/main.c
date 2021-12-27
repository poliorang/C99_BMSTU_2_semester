//mct_02_01_10
#include "strings.h"

#define ARG_ERROR -1
#define FILE_ERROR -2

int main(int argc, char *argv[])
{
    FILE *f;
    char str[SIZE];
    int flag = 0;

    if (argc != 3)
        return ARG_ERROR;

    f = fopen(argv[1], "r");

    if (f == NULL)
        return FILE_ERROR;

    while (!input(f, str))
    {
        change_string(str, argv[2]);
        if (!is_palindrome(str))
        {
            flag = 1;
            printf("%s\n", str);
        }
    }

    if (!flag || feof(f) || ferror(f))
    {
        fclose(f);
        return EXIT_FAILURE;
    }

    fclose(f);

    return EXIT_SUCCESS;
}
