#include <stdio.h>

void print_mult_table(int w, int h)
{
    for (int i = w - 1; i >= 0; --i)
    {
        for (int j = h - 1; j >= 0; --j)
            printf(" %3d", (w-i) * (h-j));
        
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    print_mult_table(6, 6);
}

