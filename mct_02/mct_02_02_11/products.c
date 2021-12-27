#include <unistd.h>
#include "products.h"

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

double average(FILE *f, long *count)
{
    double aver = 0.0, sum = 0;
    product_t product = { 0 };

    if (fseek(f, 0L, SEEK_SET))
        return -1;
    while (fread(&product, sizeof (product_t), 1, f))
    {
        sum += product.weight;
        (*count)++;
    }
    aver = sum /= (*count);
    return aver;
}

int put_by_pos(FILE *f, long pos, product_t *product)
{
    if (fseek(f, pos * (long)sizeof (product_t), SEEK_SET))
        return EXIT_FAILURE;
    fwrite(product, sizeof (product_t), 1, f);
    return EXIT_SUCCESS;
}

int delete_on_average(FILE *f, double avg, char filename[])
{
    product_t product = { 0 };
    size_t del = 0;
    size_t origin = 0;

    if (fseek(f, 0L, SEEK_SET))
        return EXIT_FAILURE;

    while (fread(&product, sizeof (product_t), 1, f))
    {
        if (product.weight < avg)
        {
            del++;
            continue;
        }
        if (put_by_pos(f, origin, &product))
            return EXIT_FAILURE;
        del++;
        origin++;
        if (fseek(f, del * sizeof (product_t), SEEK_SET))
            return EXIT_FAILURE;
    }
    if (del > origin)
        truncate(filename, origin * sizeof (product_t));

    return EXIT_SUCCESS;
}


//secondary functions
int read_bin(FILE *f)
{
    product_t  product = { 0 };
    while (fread(&product, sizeof (product_t), 1, f))
    {
        printf("%s\n",  product.name);
        printf("%" PRIu32,  product.weight);
        printf("\n\n");
    }
    return EXIT_SUCCESS;
}

int create_bin(FILE *f)
{
    product_t product = { 0 };
    while (scanf("%s" "%" SCNu32, product.name, &product.weight) == 2)
        fwrite(&product, sizeof (product_t), 1, f);
    return EXIT_SUCCESS;
}
