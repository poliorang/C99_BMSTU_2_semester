#include <stdlib.h>
#include "shortstrings.h"

#define ERROR_LEN_WORD 1
#define WORD_OVERFLOW -2
#define OVERFLOW -1

int main(void)
{
    shortstring_t str, new_str;
    shortstring_t separators = ".,!?:;- ";
    shortstrings_t words;

    str[0] = 0;
    new_str[0] = 0;
    words[0][0] = 0;

    int read_res = readline(str, SIZE);

    if (read_res == -1)
    {
        printf("Overflow");
        return OVERFLOW;
    }
    if (!read_res)
        return EXIT_FAILURE;
    int n = divide_into_words(str, words, separators);
    if (n < 0)
    {
        printf("Too long word");
        return WORD_OVERFLOW;
    }
    if (!create_line(new_str, words, n))
    {
        printf("All words have been deleted");
        return ERROR_LEN_WORD;
    }
    printf("Result:%s\n", new_str);
    return EXIT_SUCCESS;
}
