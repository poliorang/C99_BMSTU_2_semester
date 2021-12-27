#include "shortstrings.h"
#include <ctype.h>

#define WORD_LEN 17
#define WORD_OVERFLOW -2


int readline(shortstring_t str, size_t max_len)
{
    if (fgets(str, max_len + 2, stdin) == NULL || strlen(str) > max_len)
        return -1;
    if (str[0] == '\n')
        return 0;
    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = 0;
    return strlen(str);
}

//1
char *my_strpbrk(const char *s1, const char *s2)
{
    char *p = (void*)&s1[strlen(s1)];
    for (int i = 0; s1[i]; i++)
        for (int j = 0; s2[j]; j++)
            if ((s1[i] == s2[j]) && (&s1[i] < p))
                p = (void*)&s1[i];
    if (*p == s1[strlen(s1)])
        return NULL;
    return p;
}

size_t my_strspn(const char *s1, const char *s2)
{
    size_t len = 0;
    for (int i = 0; s1[i]; i++)
    {
        int flag = 0;
        for (int j = 0; s2[j]; j++)
            if (s1[i] == s2[j])
                flag = 1;
        if (!flag)
            return len;
        len++;
    }
    return len--;
}

size_t my_strcspn(const char *s1, const char *s2)
{
    size_t len = 0;
    for (int i = 0; s1[i]; i++)
    {
        for (int j = 0; s2[j]; j++)
            if (s1[i] == s2[j])
                return len;
        len++;
    }
    return len--;
}

char *my_strchr(const char *s, int c)
{
    for (size_t i = 0; i <= strlen(s); i++)
        if (s[i] == c)
            return (void*)&s[i];
    return NULL;
}

char *my_strrchr(const char *s, int c)
{
    for (int i = strlen(s); i >= 0; i--)
        if (s[i] == c)
            return (void*)&s[i];
    return NULL;
}

//2
int split(shortstring_t str, shortstrings_t words, shortstring_t separators, size_t max_len, size_t *count)
{
    size_t i = 0, j = 0, k = 0;
    words[0][0] = 0;
    while (str[k])
    {
        if (!strchr(separators, str[k]))
        {
            words[i][j] = str[k];
            j++;
        }
        else
        {
            words[i][j] = 0;
            if (j > max_len)
                return EXIT_FAILURE;
            j = 0;
            i++;
        }
        k++;
    }

    words[i][j] = 0;
    *count = i + 1;
    return EXIT_SUCCESS;
}

int word_met_once(size_t i, shortstrings_t str1, size_t count1, shortstrings_t str2, size_t count2)
{
    for (size_t j = 0; j < count1; j++)
        if (i != j && !strcmp(str1[i], str1[j]))
            return EXIT_FAILURE;
    for (size_t j = 0; j < count2; j++)
        if (!strcmp(str1[i], str2[j]))
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

//3
int divide_into_words(shortstring_t str, shortstrings_t words, shortstring_t separators)
{
    size_t n = 0;
    char *word = strtok(str, separators);
    if (strlen(word) > WORD_LEN)
        return WORD_OVERFLOW;
    for (size_t i = 0; word != NULL; i++, n++)
    {
        strcpy(words[i], word);
        word = strtok(NULL, separators);
    }
    return n;
}

void delete_symbol(shortstring_t word, size_t k)
{
    while (word[k])
    {
        word[k] = word[k + 1];
        k++;
    }
}

int create_line(shortstring_t new_str, shortstrings_t words, int n)
{
    int flag = 0;
    for (int i = n - 2; i >= 0; i--)
        if (strcmp(words[i], words[n - 1]))
        {
            flag = 1;
            size_t count = strlen(words[i]);
            for (size_t j = 0; j < count - 1; j++)
                for (size_t k = j + 1; k < count; k++)
                    if (words[i][k] == words[i][j])
                    {
                        delete_symbol(words[i], k);
                        k--;
                        count--;
                    }
            strcat(new_str, " ");
            strcat(new_str, words[i]);
        }
    return flag;
}

//4
int is_telephone_number(shortstring_t str, size_t n)
{
    size_t i = n - 1;
    while (isspace(str[i]))
        i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
            return EXIT_FAILURE;
    i--;
    if (str[i] != '-')
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (str[i] != '-')
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (str[i] != '-')
        return EXIT_FAILURE;
    i--;
    if (str[i] != ')')
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (!isdigit(str[i]))
        return EXIT_FAILURE;
    i--;
    if (str[i] != '(')
        return EXIT_FAILURE;
    if (i == 0)
        return EXIT_SUCCESS;
    i--;
    if (i > 0)
    {
        if (isspace(str[i]))
            while (i > 0)
            {
                i--;
                if (!isspace(str[i]))
                    return EXIT_FAILURE;
            }
        else
        {
            while (isdigit(str[i]))
                i--;
            if (str[i] != '+')
                return EXIT_FAILURE;
            while (i > 0)
            {
                i--;
                if (!isspace(str[i]))
                    return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

