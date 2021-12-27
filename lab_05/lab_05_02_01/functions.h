#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>

int process(FILE *f, double mean, int *count);
int find_min_and_max(FILE *f, double *min_num, double *max_num);

#endif
