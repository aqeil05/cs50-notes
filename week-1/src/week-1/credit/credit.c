#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int checking(long credit_num);
int countDigits(long num);
void brand_card(int length, long credit_num);

int main(void)
{
    long credit_num = get_long("Number: ");
    int final_num = checking(credit_num);
    if (final_num != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        brand_card(countDigits(credit_num), credit_num);
    }
}

int checking(long credit_num)
{
    int length_num = countDigits(credit_num);
    long copied_credit_num = credit_num;
    int sum;
    for (int i = 0; i < length_num; i++)
    {
        int last_digit = copied_credit_num % 10;
        copied_credit_num = copied_credit_num / 10;
        if (i % 2 == 0) // Means go alg B
        {
            sum = sum + last_digit;
        }
        else
        {
            int multiplied = last_digit * 2;
            sum = sum + (multiplied % 10);
            sum = sum + (multiplied / 10);
        }
    }
    int final_num = sum % 10;
    return final_num;
}
int countDigits(long n)
{

    // Base case
    if (n == 0)
        return 1;

    int count = 0;

    // Iterate till n has digits remaining
    while (n != 0)
    {

        // Remove rightmost digit
        n = n / 10;

        // Increment digit count by 1
        ++count;
    }
    return count;
}

void brand_card(int length, long credit_num)
{
    do
    {
        credit_num = credit_num / 10;
    }
    while (credit_num > 100);

    int final_two_digit = credit_num;
    int final_digit = final_two_digit / 10;
    if (length == 15 && (final_two_digit == 34 || final_two_digit == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 &&
             (final_two_digit == 51 || final_two_digit == 52 || final_two_digit == 53 ||
              final_two_digit == 54 || final_two_digit == 55)
            )
    {
        printf("MASTERCARD\n");
    }
    else if (length == 13 && final_digit == 4)
    {
        printf("VISA\n");
    }
    else if (length == 16 && final_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
