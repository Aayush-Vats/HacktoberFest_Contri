#include <stdio.h>

int main()
{
    int x = 47;
    int *j = &x;

    printf("Address is %u\n", j);
    printf("Value is %d", *j);
    return 0;
}