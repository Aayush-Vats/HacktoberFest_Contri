#include <stdio.h>

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int mid, int low, int high)
{
    int i, j, k, b[100];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int x = 0; x <= high; x++)
    {
        a[x] = b[x];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[] = {2, 7, 19, 4, 9, 13};
    int len = sizeof(a) / sizeof(int);

    printf("Before Sorting\n");
    printarray(a, len);

    merge_sort(a, 0, len - 1);

    printf("After Sorting\n");
    printarray(a, len);
    return 0;
}