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
