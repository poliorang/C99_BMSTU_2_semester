#ifndef _SHORTSTRING_H_
#define _SHORTSTRING_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 257
#define N 512

typedef char shortstring_t[SIZE];
typedef shortstring_t shortstrings_t[N];

int readline(shortstring_t str, size_t max_len);

//1
char *my_strpbrk(const char *s1, const char *s2);
size_t my_strspn(const char *s1, const char *s2);
size_t my_strcspn(const char *s1, const char *s2);
char *my_strchr(const char *s, int c);
char *my_strrchr(const char *s, int c);

//2
int split(shortstring_t str, shortstrings_t words, shortstring_t separators, size_t max_len, size_t *count);
int word_met_once(size_t i, shortstrings_t str1, size_t count1, shortstrings_t str2, size_t count2);

//3
int divide_into_words(shortstring_t str, shortstrings_t words, shortstring_t separators);
int create_line(shortstring_t new_str, shortstrings_t words, int n);
void delete_symbol(shortstring_t word, size_t k);

//4
int is_telephone_number(shortstring_t str, size_t n);

#endif
