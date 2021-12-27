#include "shortstrings.h"

int main(void)
{
    int count = 0, count_all = 0;
    setbuf(stdout, NULL);
    //1

    {
        char str1[] = "12345";
        char str2[] = "43";
        if (my_strpbrk(str1, str2) == strpbrk(str1, str2))
            count++;
        count_all++;
    }
    {
        char str1[] = "crycrycry";
        char str2[] = "ya";
        if (my_strpbrk(str1, str2) == strpbrk(str1, str2))
            count++;
        count_all++;
    }
    {
        char str1[] = "feytdsk";
        char str2[] = "ef";
        if (my_strpbrk(str1, str2) == strpbrk(str1, str2))
            count++;
        count_all++;
    }

    //2
    {
        char str1[] = "12345";
        char str2[] = "43";
        if (my_strspn(str1, str2) == strspn(str1, str2))
            count++;
        count_all++;
    }
    {
        char str1[] = "crycrycry";
        char str2[] = "ya";
        if (my_strspn(str1, str2) == strspn(str1, str2))
            count++;
        count_all++;
    }
    {
        char str1[] = "feytdsk";
        char str2[] = "334";
        if (my_strspn(str1, str2) == strspn(str1, str2))
            count++;
        count_all++;
    }
    //3
    {
        char str1[] = "feytdsk";
        char str2[] = "ef";
        if (my_strcspn(str1, str2) == strcspn(str1, str2))
            count++;
        count_all++;
    }

    {
        char str1[] = "12345";
        char str2[] = "43";
        if (my_strcspn(str1, str2) == strcspn(str1, str2))
            count++;
        count_all++;
    }
    {
        char str1[] = "crycrycry";
        char str2[] = "ya";
        if (my_strcspn(str1, str2) == strcspn(str1, str2))
            count++;
        count_all++;
    }
    //4
    {
        char str1[] = "fesytdsk";
        int c = 's';
        if (my_strchr(str1, c) == strchr(str1, c))
            count++;
        count_all++;
    }
    {
        char str1[] = "feytdsk";
        int c = 'w';
        if (my_strchr(str1, c) == strchr(str1, c))
            count++;
        count_all++;
    }
    {
        char str1[] = "12345";
        int c = 2;
        if (my_strchr(str1, c) == strchr(str1, c))
            count++;
        count_all++;
    }
    //5
    {
        char str1[] = "fesytdsk";
        int c = 's';
        if (my_strrchr(str1, c) == strrchr(str1, c))
            count++;
        count_all++;
    }
    {
        char str1[] = "feytdsk";
        int c = 'w';
        if (my_strrchr(str1, c) == strrchr(str1, c))
            count++;
        count_all++;
    }
    {
        char str1[] = "12345";
        int c = 2;
        if (my_strrchr(str1, c) == strrchr(str1, c))
            count++;
        count_all++;
    }
    printf("PASSED: %d/%d ", count, count_all);
}
