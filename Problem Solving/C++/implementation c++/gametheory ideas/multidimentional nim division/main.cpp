/*  Game Description-
 "A game is played between two players and there are N piles
 of stones such that each pile has certain number of stones.
 On his/her turn, a player selects a pile and can take any
 non-zero number of stones upto 3 (i.e- 1,2,3)
 The player who cannot move is considered to lose the game
 (i.e., one who take the last stone is the winner).
 Can you find which player wins the game if both players play
 optimally (they don't make any mistake)? "

 A Dynamic Programming approach to calculate Grundy Number
 and Mex and find the Winner using Sprague - Grundy Theorem. */

#include<bits/stdc++.h>
using namespace std;

/* piles[] -> Array having the initial count of stones/coins
            in each piles before the game has started.
   n       -> Number of piles

   Grundy[] -> Array having the Grundy Number corresponding to
             the initial position of each piles in the game

   The piles[] and Grundy[] are having 0-based indexing*/

#define PLAYER1 1
#define PLAYER2 2

// A Function to calculate Mex of all the values in that set
int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

// A function to Compute Grundy Number of 'n'
int calculateGrundy (int n, int Grundy[])
{
	if (n == 0)
		return (0);

	if (Grundy[n] != -1)
		return (Grundy[n]);

	unordered_set<int> Set; // A Hash Table

	Set.insert (calculateGrundy (n/2, Grundy));
	Set.insert (calculateGrundy (n/3, Grundy));
	Set.insert (calculateGrundy (n/6, Grundy));

	// Store the result
	Grundy[n] = calculateMex (Set);
	return (Grundy[n]);
}

// A function to declare the winner of the game
void declareWinner(int whoseTurn, int piles[],
                    int Grundy[], int n)
{
    int xorValue = Grundy[piles[0]];

    for (int i=1; i<=n-1; i++)
        xorValue = xorValue ^ Grundy[piles[i]];

    if (xorValue != 0)
    {
        if (whoseTurn == PLAYER1)
            printf("Player 1 will win\n");
        else
            printf("Player 2 will win\n");
    }
    else
    {
        if (whoseTurn == PLAYER1)
            printf("Player 2 will win\n");
        else
            printf("Player 1 will win\n");
    }

    return;
}


// Driver program to test above functions
int main()
{
    // Test Case 1
    int piles[] = {3, 4, 5};
    int n = sizeof(piles)/sizeof(piles[0]);

    // Find the maximum element
    int maximum = *max_element(piles, piles + n);

    // An array to cache the sub-problems so that
    // re-computation of same sub-problems is avoided
    int Grundy[maximum + 1];
    memset(Grundy, -1, sizeof (Grundy));

    // Calculate Grundy Value of piles[i] and store it
    for (int i=0; i<=n-1; i++)
        calculateGrundy(piles[i], Grundy);

    declareWinner(PLAYER1, piles, Grundy, n);

    /* Test Case 2
    int piles[] = {3, 8, 2};
    int n = sizeof(piles)/sizeof(piles[0]);


    int maximum = *max_element (piles, piles + n);

    // An array to cache the sub-problems so that
    // re-computation of same sub-problems is avoided
    int Grundy [maximum + 1];
    memset(Grundy, -1, sizeof (Grundy));

    // Calculate Grundy Value of piles[i] and store it
    for (int i=0; i<=n-1; i++)
        calculateGrundy(piles[i], Grundy);

    declareWinner(PLAYER2, piles, Grundy, n);   */

    return (0);
}
