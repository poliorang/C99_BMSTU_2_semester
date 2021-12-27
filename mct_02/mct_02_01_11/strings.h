#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 257

int input(FILE *f, char str[]);
void del_symb(char str[], size_t pos);
int is_palindrome(char str[]);
void change_string(char str[], char substr[]);

#endif
