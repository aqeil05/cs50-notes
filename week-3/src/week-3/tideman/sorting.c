#include <stdbool.h>
#include <stdio.h>

void bubbleSort(pair pairs[], int n)
void swap(int* xp, int* yp);


int preferences[3][3] = {
    { 0, 5, 3 },
    { 1, 0, 2 },
    { 2, 4, 0 }
};

typedef struct
{
    int winner;
    int loser;
} pair;

pair pairs[] = {
    {0, 1},
    {0, 2},
    {2, 1}
};
int pair_count = 3;


int main(void)
{

}


void swap(pair* xp, pair* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(pair pairs[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i ++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            int winner_index_0 = pairs[j].winner;
            int loser_index_0 = pairs[j].loser;
            int winner_index_1 = pairs[j + 1].winner;
            int loser_index_1 = pairs[j + 1].loser;
            if (preferences[winner_index_0][loser_index_0] >
                preferences[winner_index_1][loser_index_1])
                {
                    swap(&pairs[j], &pairs[j + 1]);
                    swapped = true;
                }
        }
        if (swapped = false)
        {
            break;
        }
    }
}

