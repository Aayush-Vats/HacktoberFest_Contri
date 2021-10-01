#include <stdio.h>

int main()
{
    int i = 1;
    int *p1;
    int **p2;

    p1 = &i;
    p2 = &p1;

    printf("the value of i is %d\n", **p2);

    return 0;
}