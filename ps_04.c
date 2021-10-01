#include <stdio.h>

int main()
{
    int a[10];
    int x;
    printf("Enter a number:");
    scanf("%d", &x);
    for (int i = 0; i <= 9; i++)
    {
        a[i] = x * (i + 1);
    }
    printf("Multiplication table of %d:-\n", x);
    for (int i = 0; i <= 9; i++)
    {
        printf("%d x %d = %d\n", x, (i + 1), a[i]);
    }
    return 0;
}