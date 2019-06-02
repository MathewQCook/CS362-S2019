/*
Name: Mathew Cook
Course: CS362
Assignment 5

Unit Testing for smithyCard Function
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
	int result = 0;
	//Setup deck for game initialization - swapped in salvager and sea_hag for testing
	int k[10] = { adventurer, salvager, minion, sea_hag, embargo, mine, cutpurse, baron, tribute, smithy };
	//Initialize the game with 2 players
	initializeGame(2, k, 100, &GameSt);

	//Trigger the smithyCard function via cardEffect function
	cardEffect(smithy, 0, 0, 0, &GameSt, 0, 0);
	int postCards = numHandCards(&GameSt); //Should now be 7, 3 cards added and 1 card (the smithy card) discarded
	assert(postCards == 7);
	printf("cardEffect function passed.\n");

	printf("Smithy card test complete.\n");


	return 0;
}
