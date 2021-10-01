#include <stdio.h>

int main()
{
    int a[10];
    for (int i = 0; i <= 9; i++)
    {
        a[i] = (9 * i) + 1;
    }
    int *ptr = &a[0];
    printf("value of 3rd element of array is %d\n", *(ptr + 2));
    //printf("value of 3rd element of array is %d\n", a[2]);    //check with this, if same value then correct.
    return 0;
}