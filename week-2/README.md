# Week 2

- Topics covered include data structure such as arrays
## Arrays

- Arrays are data structure which occupy contiguous location in memory
- Strings are an array of characters, ending with a '/0' (null character)
- string s = "hello", consists of 6 characters, inclusive of the null character
```
int main(void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}
```
- The output is as following
> Hi!\
> BYE!
