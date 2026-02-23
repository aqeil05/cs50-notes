# Week 1

- Topics covered in week 1 -> functions, loops, data types, libraries

## Standard boilerplate

```
#include <stdio.h>

int main(void)
{
    printf("hello world");
}
```
- <stdio.h> refers to basic input and output through the CLI

## Data types
- Boolean, int, char, long etc are examples of data types

## Functions
- Functions are used to simplify the main function and is used for repeated actions.
- Functions allow for different parameters and different return data types

# Problem examples 

## Mario

- Mario problem set is designed to tackle functions. We are supposed to create an image
- Based on how many rows we want, we are supposed to print an image like this
```
  #
 ##
###

```
- In this case, 3 rows
- We are supposed to take advantage of functions that take multiple paramaters and loops to keep track of how many
```
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

```

