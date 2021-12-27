#ifndef _SIZECREATE_H_
#define _SIZECREATE_H_

#include <stdio.h>
#include <stdlib.h>

int output_numbers(FILE *f);
int get_number_by_pos(FILE *f, long pos);
void put_number_by_pos(FILE *f, long pos, int num);
void sort(FILE *f);
int create_bin(FILE *f);
int file_size(FILE *f, long *size);
int create_file(FILE *f, long number);

#endif

