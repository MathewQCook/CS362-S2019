/*
Name: Mathew Cook
Course: CS362
Assignment 3

Unit Testing for isGameOver function
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

	//Initially testing that the game is NOT over
	int notOver = isGameOver(&GameSt);
	assert(notOver == 0);
	printf("Testing that the game is NOT over - passed.\n");

	//Set province pile to 0 to signal that the game should end
	GameSt.supplyCount[province] = 0;

	//Test to see if game is over
	int over = isGameOver(&GameSt);
	assert(over == 1);
	printf("Testing that the game is over - passed.\n");

	printf("Testing for isGameOver complete.\n");

	return 0;
}