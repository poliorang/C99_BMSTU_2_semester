//lab_04_04_03
#include "shortstrings.h"
#define OVERFLOW -1

int main(void)
{
    shortstring_t str;
    int n = readline(str, SIZE);
    if (n == -1)
        return OVERFLOW;
    if (is_telephone_number(str, n))
        printf("NO");
    else
        printf("YES");
    return EXIT_SUCCESS;
}
