//lab_05_01_06
#include "process.h"
#include <string.h>

#define NO_NUM -1
#define SHORT_SEQUENCE -2

int up_or_down(int prev, int cur)
{
    if (prev < cur)
        return 1;
    if (prev > cur)
        return -1;
    return 0;
}

int max_l(FILE *f)
{
    int cur, prev;
    int flag, flag_one = 0;
    int len = 1, max_len = 0;

    if (fscanf(f, "%d", &prev) != 1)
    {
        printf("No numbers");
        return NO_NUM;
    }
    if (fscanf(f, "%d", &cur) != 1)
    {
        printf("Short sequence");
        return SHORT_SEQUENCE;
    }
    if (prev != cur)
    {
        len++;
        flag_one = 1;
    }
    flag = up_or_down(prev, cur);
    prev = cur;

    while (fscanf(f, "%d", &cur) == 1)
    {
        if ((prev < cur && flag != 1) || (prev > cur && flag != -1) || (prev == cur))
        {
            if (prev != cur)
                flag_one = 1;
            if (len > max_len)
                max_len = len;
            len = 1;
            flag = up_or_down(prev, cur);
        }
        len++;
        prev = cur;
    }

    if (len > max_len)
        max_len = len;
    if (!flag_one)
        max_len = 0;

    printf("%d", max_len);
    return EXIT_SUCCESS;
}

