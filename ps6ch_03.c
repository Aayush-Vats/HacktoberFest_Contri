#include <stdio.h>
void a(int *i);

int main()
{
    int x = 47;
    int *j = &x;
    printf("Address is %u\n", j);
    printf("Value is %d\n", *j);
    a(&x); // you can also write a(j) here as well
    return 0;
}
void a(int *i)
{
    int y = *i;
    int k = 10 * y;
    printf("Address is %d\n", k);
}