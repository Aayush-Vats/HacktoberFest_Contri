#include <stdio.h>

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quick_sort(int a[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quick_sort(a, low, partitionIndex - 1);
        quick_sort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int a[] = {2, 7, 19, 4, 9, 13};
    int len = sizeof(a) / sizeof(int);

    printf("Before Sorting\n");
    printarray(a, len);

    quick_sort(a, 0, len - 1);

    printf("After Sorting\n");
    printarray(a, len);
    return 0;
}