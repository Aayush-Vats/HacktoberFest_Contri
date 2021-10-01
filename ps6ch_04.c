#include <stdio.h>
int sum(int *x, int *y);
float avg(int *x, int *y);

int main()
{
    int a = 22;
    int b = 33;
    printf("Sum of %d and %d is %d\n", a, b, sum(&a, &b));
    printf("Average of %d and %d is %0.3f\n", a, b, avg(&a, &b));

    return 0;
}
int sum(int *x, int *y)
{
    int s = *x + *y;
    return s;
}

float avg(int *x, int *y)
{
    int a = *x;
    int b = *y;
    int s = sum(&a, &b);
    float f = s / 2.0; //float f= (float) s/2; [This is called type conversion.]
    return f;
}

// //ANOTHER WAY TO SOLVE THIS PROBLEM
// #include<stdio.h>
// void sumAndAvg (int a, int b, int *s, float *av)
// {
//     *s = a + b;
//     *av = (float) (*s)/2;
// }
// int main(){
//     int i= 3;
//     int j = 6;
//     int sum, float avg;
//     sumAndAvg (i, j, &sum, &avg);
//     printf("Sum of %d and %d is %d\n", i, j, sum);
//     printf("Average of %d and %d is %0.3f\n", i, j, avg);
    
//     return 0;
// }