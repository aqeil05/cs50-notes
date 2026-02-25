#include <cs50.h>
#include <stdio.h>

void meow(int n);

//First thing is output. For example void means im not returning any value, only printing. int meow means im returning an int
int main(void)
{
    int n = 0;
    while (n <= 0){
        n = get_int("how many meows\n");
    }
    meow(n);
}


void meow(int n)
{
    for (int i = 0; i < n; i ++)
    {
        printf("meow\n");
    }
}
