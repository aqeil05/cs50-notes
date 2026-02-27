#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Create an array for the winners
int winners[MAX];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void bubbleSort(int n);
void swap(pair *xp, pair *yp);
bool check_cycle(int winner, int loser);
bool check_loser(int winner);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0) // The candidate is valid
        {
            // Update ranks
            ranks[rank] = i; // So imagine I am at Alice, if the name is correct, store the index
                             // Alice, 0, at the array.
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int preferred;
    int not_preferred;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++) // Comparing preference {[0,1],[0,2],[1,2]}
        {
            preferred = ranks[i];
            not_preferred = ranks[j];
            preferences[preferred][not_preferred] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((preferences[i][j] > 0) && (preferences[i][j] > preferences[j][i]))
            {
                // There are people that prefer candidate i over candidate j and they are not equal
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count += 1;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    bubbleSort(pair_count);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (check_cycle(winner, loser))
        {
            continue;
        }
        else
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int w = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        // Index i is the winner and index j is the loser. Need to check if index i loses to anyone
        if (!check_loser(i)) // This doesnt lose to anything
        {
            winners[w] = i;
            w += 1;
        }
        else
        {
            continue;
        }
    }
    for (int f = 0; f < w; f++)
    {
        int winner_index = winners[f];
        printf("%s\n", candidates[winner_index]);
    }
    return;
}

bool check_loser(int winner)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][winner] && (i != winner))
        {
            return true; // Winner does have a loser. Therefore not the overall winner
        }
    }
    return false;
}

void swap(pair *xp, pair *yp)
{
    pair temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            int strength_0 = preferences[pairs[j].winner][pairs[j].loser] -
                             preferences[pairs[j].loser][pairs[j].winner];
            int strength_1 = preferences[pairs[j + 1].winner][pairs[j + 1].loser] -
                             preferences[pairs[j + 1].loser][pairs[j + 1].winner];

            if (strength_0 < strength_1)
            {
                swap(&pairs[j], &pairs[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

bool check_cycle(int winner, int loser)
{
    bool cycle = false;
    if (winner == loser)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[loser][i])
            {
                if (check_cycle(winner, i))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
