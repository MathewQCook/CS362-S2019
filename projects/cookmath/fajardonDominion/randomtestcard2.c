/*
Name: Mathew Cook
Course: CS362
Assignment 4

Random testing for salvager card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main() {
	//Establish instance of gamestate
	struct gameState GameSt;
	//Setup deck for game initialization - swapped in salvager and sea_hag for testing
	int k[10] = { adventurer, salvager, minion, sea_hag, embargo, mine, cutpurse, baron, tribute, smithy };

	//Test loop variables
	int testCnt = 1000;
	int successBuys = 0;
	int failureBuys = 0;
	int successCoins = 0;
	int failureCoins = 0;
	int i;
	int seed = rand() % 1000;

	for (i = 0; i < testCnt; i++) {

		//Establish random variables for game initialization
		int plrs = (rand() % 4) + 1;

		//Initialize the game with random variables
		initializeGame(plrs, k, seed, &GameSt);

		//Randomly decide whose turn it is
		int j;
		for (j = 0; j < (rand() % plrs); j++) {
			endTurn(&GameSt);
		}

		//Check current player's initial number of buys and coins
		int preBuys = GameSt.numBuys;
		int preCoins = GameSt.coins;

		//Trigger the salvagerCard function via cardEffect function
		cardEffect(salvager, 1, 0, 0, &GameSt, 0, 0);

		//Check player 1's number of buys and coins post card being played
		int postBuys = GameSt.numBuys;
		int postCoins = GameSt.coins;
		int buysDif = postBuys - preBuys;
		int coinsDif = postCoins - preCoins;

		if (buysDif == 1) {
			printf("Increase number of buys test passed.\n");
			successBuys++;
		}
		else {
			printf("Increase number of buys test failed.\n");
			failureBuys++;
		}

		if (coinsDif > 0) {
			printf("Increase coins test passed.\n");
			successCoins++;
		}
		else {
			printf("Increase coins test failed.\n");
			failureCoins++;
		}

	}

	printf("Salvager card test completed %d time, with %d buys passes and %d buys fails.  And %d coins passes and %d coins fails.\n", testCnt, successBuys, failureBuys, successCoins, failureCoins);

	return 0;
}