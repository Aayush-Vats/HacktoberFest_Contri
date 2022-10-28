#include<stdio.h>
#include<stdlib.h>

void printarray(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int a[], int n)
{
    int max = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void count_sort(int a[], int n)
{
    int i, j;
    int max = maximum(a, n);
    int* count = (int *) malloc((max + 1) * sizeof(int));
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0; // counter for count array
    j = 0; // counter for given array a

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int a[] = {2, 7, 4, 4, 3, 3};
    int len = sizeof(a) / sizeof(int);

    printf("Before Sorting\n");
    printarray(a, len);

    count_sort(a, len);

    printf("After Sorting\n");
    printarray(a, len);

    return 0;
}