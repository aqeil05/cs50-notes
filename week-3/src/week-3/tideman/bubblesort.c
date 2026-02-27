// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

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

int preferences[3][3] = {
    { 0, 5, 3 },
    { 1, 0, 2 },
    { 2, 4, 0 }
};

void swap(pair* xp, pair* yp){
    pair temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
        int strength_0 = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
        int strength_1 = preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner];

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

// Function to print an array
void printArray(pair arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("Winner: %d, Loser: %d\n", arr[i].winner, arr[i].loser);
    }
}


int main(){
    bubbleSort(pair_count);
    printf("Sorted array: \n");
    printArray(pairs, pair_count);
    return 0;
}
