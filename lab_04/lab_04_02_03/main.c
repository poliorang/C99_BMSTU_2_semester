//lab_04_02_03
#include "shortstrings.h"
#define WORD_LEN 17
#define ERROR_LEN_WORD 1
#define ERROR_ALL_DELETE 2

int main(void)
{
    shortstring_t str_one, str_two;
    shortstrings_t words_one, words_two;
    shortstring_t separators = ".,!?:;- ";
    size_t count_one = 0, count_two = 0;

    int read_one = readline(str_one, SIZE);
    int read_two = readline(str_two, SIZE);

    if (read_one <= 0 || read_two <= 0)
        return EXIT_FAILURE;

    if (split(str_one, words_one, separators, WORD_LEN, &count_one))
    {
        printf("Too long word");
        return ERROR_LEN_WORD;
    }
    if (split(str_two, words_two, separators, WORD_LEN, &count_two))
    {
        printf("Too long word");
        return ERROR_LEN_WORD;
    }
    shortstrings_t result;
    result[0][0] = 0;

    size_t j = 0;
    for (size_t i = 0; i < count_one; i++)
        if (!word_met_once(i, words_one, count_one, words_two, count_two))
        {
            strcpy(result[j], words_one[i]);
            j++;
        }
    for (size_t i = 0; i < count_two; i++)
        if (!word_met_once(i, words_two, count_two, words_one, count_one))
        {
            strcpy(result[j], words_two[i]);
            j++;
        }
    if (j == 0)
    {
        printf("All words have been deleted");
        return ERROR_ALL_DELETE;
    }

    printf("Result:");
    for (size_t i = 0; i < j; i++)
        if (result[i][0])
            printf(" %s", result[i]);
    return EXIT_SUCCESS;
}
