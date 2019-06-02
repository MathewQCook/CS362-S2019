/*
Name: Mathew Cook
Course: CS362
Assignment 4

Random testing for smithy card
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
	int result = 0;
	//Setup deck for game initialization - swapped in salvager and sea_hag for testing
	int k[10] = { adventurer, salvager, minion, sea_hag, embargo, mine, cutpurse, baron, tribute, smithy };

	//Test loop variables
	int testCnt = 1000;
	int success = 0;
	int failure = 0;
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

		//Trigger the smithyCard function via cardEffect function
		cardEffect(smithy, 0, 0, 0, &GameSt, 0, 0);

		int postCards = numHandCards(&GameSt); //Should now be 7, 3 cards added and 1 card (the smithy card) discarded

		if (postCards == 7) {
			printf("Use of smithy card successful.\n");
			success++;
		}
		else {
			printf("Use of smithy card failed.  Cards in hand = %d \n", postCards);
			failure++;
		}

	}

	printf("Smithy card test completed %d time, with %d passes and %d fails.\n", testCnt, success, failure);


	return 0;
}