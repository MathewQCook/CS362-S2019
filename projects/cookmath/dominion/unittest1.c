/*
Name: Mathew Cook
Course: CS362
Assignment 3

Unit Testing the numHandCards function
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

	//Test initial number of cards in player 1's hand
	int p1 = numHandCards(&GameSt); //should be 5 cards
	assert(p1 == 5);
	printf("Initial hand count of player 1 passed.\n");

	//Test initial number of cards in player 2's hand
	endTurn(&GameSt);
	int p2 = numHandCards(&GameSt);
	assert(p2 == 5);
	printf("Initial hand count of player 2 passed.\n");

	//Modify hand count for player 1 to ensure function of state change
	GameSt.handCount[0] = p1 + 3; //Should now equal 8 cards
	assert(GameSt.handCount[0] == 8);
	printf("Modificaiton of player 1's hand count passed.\n");

	//Modify hand count for player 2 to ensure function of state change
	GameSt.handCount[1] = p2 + 2; //Should now equal 7 cards
	assert(GameSt.handCount[1] == 7);
	printf("Modification of player 2's hand count passed.\n");

	printf("Handcount testing completed.\n");
	
	return 0;
}