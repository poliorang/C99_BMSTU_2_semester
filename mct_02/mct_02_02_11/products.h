#ifndef _PRODUCTS_H_
#define _PRODUCTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define SIZE 126

#pragma pack(push, 1)
typedef struct
{
    char name[SIZE];
    uint32_t weight;
} product_t;
#pragma pack(pop)

int file_size(FILE *f, long *size);
double average(FILE *f, long *count);
int put_by_pos(FILE *f, long pos, product_t *product);
int delete_on_average(FILE *f, double avg, char filename[]);

int read_bin(FILE *f);
int create_bin(FILE *f);

#endif
