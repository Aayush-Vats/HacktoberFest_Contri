#include<stdio.h>

void printarray(int a[], int n) //can use this 'int* a' as well
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort(int* a, int n) //can use this 'int a[]' as well 
{
    for (int i = 0; i < n-2; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            int temp;
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {2, 7, 19, 4, 9, 13};
    int len = sizeof(a)/sizeof(int);
    
    printf("Before Sorting\n");
    printarray(a, len);
    
    bubble_sort(a, len);

    printf("After Sorting\n");
    printarray(a, len);
    return 0;
}