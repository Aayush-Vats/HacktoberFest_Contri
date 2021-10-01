#include <stdio.h>
void check(int x[], int y);

int main()
{
    int n;
    int a[n];
    printf("How much elements due want the array to hold:");
    scanf("%d", &n);
    for (int i = 0; i <= (n - 1); i++)
    {
        printf("Enter the value of element %d in the array:\n", i+1);
        scanf("%d", &a[i]);
    }
    check(a, n);
    return 0;
}

void check(int x[], int y)
{
    int p = 0;
    for (int i = 0; i <= y - 1; i++)
    {
        if (x[i] > 0)
        {
            p = p + 1;
        }
    }
    printf("Number of positive integers entered in the array = %d", p);
}
