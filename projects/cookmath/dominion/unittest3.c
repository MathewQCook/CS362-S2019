/*
Name: Mathew Cook
Course: CS362
Assignment 3

Unit Testing for drawCard function
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

	//Test initial number of cards in player 1's hand prior to drawCard function being invoked
	int p1 = numHandCards(&GameSt); //should be 5 cards
	assert(p1 == 5);
	printf("Initial hand count of player 1 passed.\n");

	//Invoking drawCard function and testing new count
	int drwP1 = drawCard(0, &GameSt); //Count of cards should now be 6 for player 1
	p1 = numHandCards(&GameSt);
	assert(p1 == 6);
	printf("Count after drawCard invoked passed.\n");

	//Test for condition of player 1's deck being empty
	GameSt.deckCount[0] = 0;  //Set the deck count for player 1 to equal 0 cards left
	drwP1 = drawCard(0, &GameSt);
	p1 = numHandCards(&GameSt);  //This should now equal 1 after drawing 1 card
	assert(drwP1 == -1); //-1 as a result of the deck being empty
	assert(p1 == 6);
	printf("Empty deck for player 1 passed.\n");

	printf("drawCard function test complete.\n");


	return 0;
}