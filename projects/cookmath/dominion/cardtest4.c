/*
Name: Mathew Cook
Course: CS362
Assignment 3

Unit Testing for sea_hag card Function
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
	//Initialize the game with 3 players
	initializeGame(3, k, 100, &GameSt);

	cardEffect(sea_hag, 0, 0, 0, &GameSt, 0, 0);

	int i;

	for (i = 0; i < GameSt.numPlayers; i++) {
		if (i != 0) {
			//Check if last card is curse card
			if (GameSt.hand[i][GameSt.handCount[i] - 1] == curse) {
				printf("Curse card check for player %d passed.\n", i + 1);
			}else {
				printf("Curse card check for player %d failed.\n", i + 1);
			}
		}
	}

	//Restarting the game to test direct call of sea hag function
	initializeGame(3, k, 100, &GameSt);

	seahagCard(&GameSt, 0);

	for (i = 0; i < GameSt.numPlayers; i++) {
		if (i != 0) {
			//Check if last card is curse card
			if (GameSt.hand[i][GameSt.handCount[i] - 1] == curse) {
				printf("Curse card check for player %d passed.\n", i + 1);
			}
			else {
				printf("Curse card check for player %d failed.\n", i + 1);
			}
		}
	}

	printf("Sea hag card test completed.\n");


	return 0;
}