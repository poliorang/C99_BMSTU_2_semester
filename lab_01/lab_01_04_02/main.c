/*
 lab_01_04_02
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int time;
    int ho, mi, se;
    printf("Input time\n");
    scanf("%d", &time);
    ho = time / 3600;
    mi = (time - (ho * 3600)) / 60;
    se = (time - (ho * 3600) - mi * 60);
    printf("%d %d %d", ho, mi, se);
    return EXIT_SUCCESS;
}
