#include <stdio.h>
#include <cs50.h>

void print_row(int n, int empty);

int main(void)
{
    int k;
    do
    {
        k = get_int("How many rows ");
    } while (k < 1);

    int empty = k;
    for (int j = 1; j <= k; j ++)
    {
        print_row(j, empty - 1);
        empty = empty - 1;
    }
}

void print_row(int n, int empty)
{

    for (int j = 0; j < empty; j ++)
    {
        printf(" ");
    }

    for (int i = 0; i < n; i ++)
    {
        printf("#");
    }

    printf("  ");

    for (int i = 0; i < n; i ++)
    {
        printf("#");
    }
    printf("\n");
}
