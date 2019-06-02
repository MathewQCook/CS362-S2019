/*
Name: Mathew Cook
Course: CS362
Assignment 5

Unit Testing for the adventurer card
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
	//Setup deck for game initialization - swapped in salvager and sea_hag for testing
	int k[10] = { adventurer, salvager, minion, sea_hag, embargo, mine, cutpurse, baron, tribute, smithy };
	//Initialize the game with 2 players
	initializeGame(2, k, 100, &GameSt);

	//Trigger the adventurerCard function via cardEffect function
	cardEffect(adventurer, 0, 0, 0, &GameSt, 0, 0);

	//Test last two cards in player 1's hand to see if they are treasure cards
	if (GameSt.hand[0][GameSt.handCount[0] - 1] != copper && GameSt.hand[0][GameSt.handCount[0] - 1] != silver && GameSt.hand[0][GameSt.handCount[0] - 1] != gold) {
		printf("Test failed.\n");
	}

	if (GameSt.hand[0][GameSt.handCount[0] - 2] != copper && GameSt.hand[0][GameSt.handCount[0] - 2] != silver && GameSt.hand[0][GameSt.handCount[0] - 2] != gold) {
		printf("Test failed.\n");
	}

	printf("cardEffect function passed.\n");


	printf("Adventurer card testing complete.\n");


	return 0;
}
