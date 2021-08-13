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
void print_winner(void);

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

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// TODO - Update vote totals given a new vote
bool vote(string name)
{
    // Check each of the candidate structs
    for (int i = 0; i < candidate_count; i++)
    {
        // compare the voter name with candidate name
        // if its true then add 1 to the candidates vote count
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false; // catch all - return false if the name doesnt exist in the structs
}

// Print the winner (or winners) of the electione
void print_winner(void)
{
    int winnervote_count = 0;

    // find the highest vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winnervote_count)
        {
            winnervote_count = candidates[i].votes;
        }
    }

    // print the candidates with the winning vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winnervote_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

