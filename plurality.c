#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void quick_sort(int left, int right);
void print_winner();

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        int index = 0;

        for (int it = 1; it < argc; it++)
        {
            if (strcmp(name, argv[it]) == 0)
            {
                index++;
            }
        }

        // Check for invalid vote
        if (index == 0)
        {
            printf("Invalid vote.\n");
            i = i - 1;
        }
        vote(name);
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < (candidate_count); i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {

            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }

    // TODO
    return false;
}

// Print the winner (or winners) of the election
void print_winner()
{
    int draw[candidate_count], lenghtArrayFilled = 0, i;
    //sort array candidates
    quick_sort(0, candidate_count - 1);
    //create array draw
    for (i = 0; i < candidate_count; i++)
    {
        if (candidates[candidate_count - 1].votes == candidates[i].votes)
        {
            draw[i] = i;
        }
    }
    //count lenght array Filled
    for (i = 0; i < candidate_count; i++)
    {
        if (draw[i] < candidate_count)
        {
            lenghtArrayFilled++;
        }
    }
    // print winner or draw
    if (lenghtArrayFilled == 1)
    {
        printf("%s\n", candidates[candidate_count - 1].name);
    }
    else
    {
        for (i = 0; i < lenghtArrayFilled ; i++)
        {
            printf("%s\n", candidates[draw[i]].name);
        }
    }

    return;
}
void quick_sort(int left, int right)
{
    int i, j, x;
    candidate y = candidates[0];

    i = left;
    j = right;
    x = candidates[(i + j) / 2].votes;


    while (i <= j)
    {
        while (candidates[i].votes < x && i < right)
        {
            i++;
        }
        while (candidates[j].votes > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = candidates[i];
            candidates[i] = candidates[j];
            candidates[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(left, j);
    }
    if (i < right)
    {
        quick_sort(i, right);
    }
}