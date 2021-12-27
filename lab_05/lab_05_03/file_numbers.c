#include <time.h>
#include "file_numbers.h"

int create_file(FILE *f, long number)
{
    long num;
    srand(time(NULL));
    for (long i = 0; i < number; i++)
    {
        num = rand() % 100;
        fwrite(&num, sizeof(long), 1, f);
    }
    return EXIT_SUCCESS;
}

int output_numbers(FILE *f)
{
    int num;

    while (fread(&num, sizeof(int), 1, f) == 1)
        printf("%d ", num);
    return EXIT_SUCCESS;
}

int get_number_by_pos(FILE *f, long pos)
{
    int num;
    fseek(f, pos * sizeof (int), SEEK_SET);
    fread(&num, sizeof (int), 1, f);
    return num;
}

void put_number_by_pos(FILE *f, long pos, int num)
{
    fseek(f, pos * sizeof (int), SEEK_SET);
    fwrite(&num, sizeof (int), 1, f);
}

void sort(FILE *f)
{
    long k = 0;
    file_size(f, &k);
    k /= sizeof (int);
    int a, b;

    for (long i = 0; i < k - 1; i++)
        for (long j = 0; j < k - i - 1; j++)
        {
            a = get_number_by_pos(f, j);
            b = get_number_by_pos(f, j + 1);
            if (a > b)
            {
                put_number_by_pos(f, j + 1, a);
                put_number_by_pos(f, j, b);
            }
        }
}

int file_size(FILE *f, long *size)
{
    if (fseek(f, 0L, SEEK_END))
        return EXIT_FAILURE;
    if (ftell(f) < 0)
        return EXIT_FAILURE;
    (*size) = ftell(f);
    fseek(f, 0L, SEEK_SET);
    return EXIT_SUCCESS;
}

int create_bin(FILE *f)
{
    int num;
    while (scanf("%d", &num) == 1)
        fwrite(&num, sizeof (int), 1, f);
    return EXIT_SUCCESS;
}

