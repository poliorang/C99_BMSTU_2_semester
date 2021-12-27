#include "strings.h"

int input(FILE *f, char str[])
{
    char s[SIZE + 1];

    if (!fgets(s, SIZE + 1, f))
        return EXIT_FAILURE;
    size_t len = strlen(s);
    if (len > SIZE)
        return EXIT_FAILURE;
    if (s[len - 1] == '\n')
        s[len - 1] = 0;
    strcpy(str, s);
    return 0;
}

void del_symb(char str[], size_t pos)
{
    while (str[pos])
    {
        str[pos] = str[pos + 1];
        pos++;
    }
}

int is_palindrome(char str[])
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1])
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void change_string(char str[], char substr[])
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        int flag = 0;
        for (size_t j = 0; j < strlen(substr); j++)
            if (str[i] == substr[j])
                flag = 1;
        if (flag)
        {
            del_symb(str, i);
            i--;
        }
    }
}
