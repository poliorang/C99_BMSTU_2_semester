#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define SIZE_SURNAME 26
#define SIZE_NAME 11
#define SIZE_GRADE 4

typedef struct
{
    char surname[SIZE_SURNAME];
    char name[SIZE_NAME];
    uint32_t grades[SIZE_GRADE];
} student_t;

int file_size(FILE *f, long *size);
int read_bin(FILE *f);
int create_bin(FILE *f);
double average(FILE *f);
int get_by_pos(FILE *f, long pos, student_t *a);
int put_by_pos(FILE *f, long pos, student_t a);
int del_field(FILE *f, char *filename, long pos, long *count);
int delete_on_average(FILE *f, long *count, char *filename);
int start_of_line(char *substr, char *str);
void output_substr(FILE *fin, FILE *fout, char *substr, long *count);
int sort(FILE *f);

#endif
