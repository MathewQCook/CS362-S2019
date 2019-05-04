/*
Name: Mathew Cook
Course: CS362
Assignment 3

Unit Testing for whoseTurn function
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	//Establish instance of gamestate
	struct gameState GameSt;
	//Setup deck for game initialization
	int k[10] = { adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy };
	//Initialize the game with 2 players
	int gm = initializeGame(2, k, 2, &GameSt);

	//Test that the game has been properly setup
	assert(gm == 0);

	//Test to ensure player 1's turn
	int p1 = whoseTurn(&GameSt);
	assert(p1 == 0);
	printf("whoseTurn for Player 1 passed.\n");

	//Advance turn to player 2
	endTurn(&GameSt);
	int p2 = whoseTurn(&GameSt);
	assert(p2 == 1);
	printf("whoseTurn for Player 2 passed.\n");

	printf("whoseTurn testing complete.\n");

	return 0;
}