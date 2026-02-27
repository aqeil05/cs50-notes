#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// locked[i][j] means i is locked in over j

bool locked[4][4] = {
    {false, true,  true,  false},
    {false, false, false, false},
    {false, true,  false, true },
    {false, false, false, false}
};

int winners[MAX];

string candidates[MAX] = {"Alice", "Bob", "Charlie", "David"};
int candidate_count = 4;

bool check_loser(int winner);
void print_winner(void);


int main(void)
{
    print_winner();
}


// Print the winner of the election
void print_winner(void)
{
    int w = 0;
    for (int i = 0; i < candidate_count; i ++)
    {
        // Index i is the winner and index j is the loser. Need to check if index i loses to anyone
        if (!check_loser(i)) //This doesnt lose to anything
        {
            winners[w] = i;
            w += 1;
        }
        else
        {
            continue;
        }
    }
    for (int f = 0; f < w; f ++)
    {
        printf("%i", winners[f]);
    }
    printf("are the winners\n");
    return;
}

bool check_loser(int winner)
{
    for (int i = 0; i < candidate_count; i ++)
    {
        for (int j = 0; j < candidate_count; j ++)
        {
            if (locked[i][j] && (j == winner) && (i != j))
            {
                return true; //Winner does have a loser. Therefore not the overall winner
            }
        }
    }
    return false;
}
