#include <stdio.h>

int recur_sum(int start, int end)
{
    if (start == end)
        return end;

    return start + recur_sum(start + 1, end);
}

int main(int argc, char** argv)
{
    int sum = recur_sum(1, 100);

    printf("the sum of all of the numbers [1, 100] is: %i\n", sum);
}

