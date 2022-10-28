#include <stdio.h>

void input_numbers(int arr[], int n)
{
    printf("Enter %d number/s\n", n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

/*void print_numbers(int arr[], int n)
{
    printf("The number/s are\n", n);
    for (int i = 0; i <= n-1; i++)
    {
        printf("%d\t", arr[i]);
    }
}*/

int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] == x)
            return 1;
    }
    return 0;
}

int binary_search(int arr[], int n, int x)
{
    int f = 0;
    int l = n - 1;

    while (f < l)
    {
        int mid = (f + l) / 2;
        if (arr[mid] == x)
        {
            return 1;
        }
        else if (arr[mid] < x)
        {
            f = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int ch;
    printf("Enter 1 for Linear Search.\nEnter 2 for Binary Search.\nEnter 3 for Exit: ");
    scanf("%d", &ch);

    int size;
    int arr[size];
    int num;

    switch (ch)
    {
    case 1:
    {
        printf("Enter size of the array: ");
        scanf("%d", &size);
        input_numbers(arr, size);

        printf("Enter the number you want search: ");
        scanf("%d", &num);
        if (linear_search(arr, size, num))
        {
            printf("Number Found\n");
        }
        else
        {
            printf("Number not Found\n");
        }

        // print_numbers(arr, size);
        break;
    }

    case 2:
    {
        printf("Enter size of the array: ");
        scanf("%d", &size);
        printf("REMINDER: For binary search make sure the array is sorted.\n");
        input_numbers(arr, size);

        printf("Enter the number you want search: ");
        scanf("%d", &num);

        if (binary_search(arr, size, num))
        {
            printf("Number Found\n");
        }
        else
        {
            printf("Number not Found\n");
        }
        break;
    }
    case 3:
        return 0;
    }
    return 0;
}