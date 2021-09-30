#include <stdio.h>
int Greatest(int a[], int index, int len)
{
    int max;
    if (index >= len - 2) 
    {
        if (a[index] > a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }
    max = Greatest(a, index + 1, len);
    if (a[index] > max)
        return a[index];
    else
        return max;
}
int Smallest(int a[], int index, int len)
{
    int min;
    if (index >= len - 2) {
        if (a[index] < a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }
    min = Smallest(a, index + 1, len);
    if (a[index] < min)
        return a[index];
    else
        return min;
}
void main()
{
    
    int min, max;

    int a[10], i,n;
    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d numbers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max = Greatest(a, 0, n);
    min = Smallest(a, 0, n);
    printf("The minimum number is : %d\n", min);
    printf("The maximum number is : %d", max);
}
