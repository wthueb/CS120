#include <stdio.h>

int maximum(int* a, int n)
{
    int max = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

int minimum(int* a, int n)
{
    int min = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] < min)
            min = a[i];
    }

    return min;
}

int total(int* a, int n)
{
    int sum = a[0];

    for (int i = 1; i < n; ++i)
        sum += a[i];

    return sum;
}

int average(int* a, int n)
{
    int sum = total(a, n);

    return sum / n;
}

int main()
{
    int a[] = { 3, 8, 2, 9, 4 };

    printf("the maximum is %i\n", maximum(a, 5));
    printf("the minimum is %i\n", minimum(a, 5));
    printf("the total is %i\n", total(a, 5));
    printf("the average is %i\n", average(a, 5));
}

