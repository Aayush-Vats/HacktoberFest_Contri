#include <stdio.h>
void a(int i);

    int main()
{
    int x = 47;
    int *j = &x;
    printf("Address is %u\n", j);
    printf("Value is %d\n", *j);
    a(x);
    return 0;
}
void a(int i)
{
    printf("Address is %u\n", &i); //The value of x which comes down here is different and is stored in a different loacation. 
}