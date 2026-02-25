# Week 2

- Topics covered include data structure such as arrays and command line arguments
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

- Arrays can be initialised to store any type of data
```
const int N = 50;

int scores[N];
char letters[N];
```
- Arrays can even be used for custom data structures, refer to __ for custom data structure
```
typedef struct person
{
    char* name;
    char* phonenumber;
    int identification number;
} person;

person database[100];
```
- In this case, this stores 100 persons in its database

### Strength
- Fast access

### Limitations
- Consume a lot of space, not resizable

## Command line arguments
- Command line arguments are used to allow for quick testing of data sets

```
int main(int argc, string argv[])
{
    //Main logic here
}
```
- Allows for multiple arguments
- Access arguments through argv[N], where N is the variable you want to access
> Since 0 indexed, index 0 is the name of the file, 1 onwards are the arguments\

- Example of simple programe
```
#include <cs50.h>
#include <stdio.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
        return 4;
    }

}

```

# Problem sets

## Substitution
```
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

string convert_string(string key);
string encryption(string plain_text, string key);
bool has_duplicate(string key);
bool key_validation(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key requires 26 characters!\n");
            return 1;
        }
        else
        {
            if (!key_validation(argv[1]))
            {
                return 1;
            }
            else
            {
                string key = convert_string(argv[1]);
                string user_input = get_string("Plain text: ");

               //Output the encrypted text
                printf("ciphertext: %s\n", encryption(user_input, key));
                return 0;
            }
        }
    }
    else
    {
        printf("This program accepts 2 command line arguments\n");
        return 1;
    }
}

string convert_string(string key)
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        key[i] = tolower(key[i]);
    }
    return key;
}

string encryption(string plain_text, string key)
{

    for (int i = 0, length = strlen(plain_text); i < length; i++)
    {
        char plain = plain_text[i];
        if (isupper(plain))
        {
            int key_position = plain - 'A';
            plain_text[i] = toupper(key[key_position]);
        }
        else if (islower(plain))
        {
            int key_position = plain - 'a';
            plain_text[i] = key[key_position];
        }
    }
    return plain_text;
}


bool has_duplicate(string key)
{
    for (int i = 0; i < 26; i ++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
        for (int j = 0; j < 26; j ++)
        {
            if (i != j && tolower(key[i]) == tolower(key[j]))
            {
                return true;
            }

        }
    }
    return false;
}

bool key_validation(string key)
{
    for (int i = 0; i < 26; i ++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    bool seen[26] = {false};
    for (int i = 0; i < 26; i ++)
    {
        char c = tolower(key[i]);
        int index = c - 'a';
        if (seen[index])
        {
            //Duplicate found
            return false;
            break;
        }
        else
        {
            seen[index] = true;
        }
    }
    return true;
}

```

## Learning points

1. ASCII 

- Each character is represented by a number.
- We can use this number to manipulate systems to allow for fast data processing as int is only 4 bits compared to other data types

2. Edge/Case detection
- Consider both uppercase and lowercase
- Consider what if the user types in anything other than letters in the alphabet. Do we ignore or ask for another input

3. Use boolean arrays for duplicates
- Has this appeared before? Use this for faster lookup over loops
- O(1) instead of O(n)

4. Separation through functions
- Cleaner design
