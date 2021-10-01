#include <stdio.h>
// void reverseArray(int a[], int x);
void reverseArray(int *a, int x);
int main()
{
    int a[10];
    for (int i = 0; i <= 9; i++)
    {
        a[i] = (9 * i) + 1;
    }
    reverseArray( a, 10);
    return 0;
}

// void reverseArray(int a[], int x)
void reverseArray(int *a, int x)
{
    printf("Reverse order\n");
    for (int i = x-1; i >= 0 ; i--)
    {
        printf("The value of element %d in array is %d\n", i + 1, a[i]);
    }
}
