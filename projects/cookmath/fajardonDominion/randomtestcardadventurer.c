/*
Name: Mathew Cook
Course: CS362
Assignment 4

Random testing for adventurer card
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
	//Setup deck for game initialization - swapped in salvager and sea_hag for testing
	int k[10] = { adventurer, salvager, minion, sea_hag, embargo, mine, cutpurse, baron, tribute, smithy };

	//Test loop variables
	int testCnt = 1000;
	int successTop = 0;
	int failureTop = 0;
	int successSec = 0;
	int failureSec = 0;
	int i;
	int seed = rand() % 1000;

	for (i = 0; i < testCnt; i++) {
		//Establish instance of gamestate
		struct gameState GameSt;

		//Establish random variables for game initialization
		int plrs = (rand() % 4)+1;

		//Initialize the game with random variables
		initializeGame(plrs, k, seed, &GameSt);

		//Randomly decide whose turn it is
		int j;
		for (j = 0; j < (rand() % plrs); j++) {
			endTurn(&GameSt);
		}

		int curPlyr = whoseTurn(&GameSt);

		//Trigger the adventurerCard function via cardEffect function
		cardEffect(adventurer, 0, 0, 0, &GameSt, 0, 0);

		//Test last two cards in player 1's hand to see if they are treasure cards
		if (GameSt.hand[curPlyr][GameSt.handCount[curPlyr] - 1] != copper && GameSt.hand[curPlyr][GameSt.handCount[curPlyr] - 1] != silver && GameSt.hand[curPlyr][GameSt.handCount[curPlyr] - 1] != gold) {
			printf("Checking top card: Test failed.\n");
			failureTop++;
		}
		else {
			printf("Checking top card: Test passed.\n");
			successTop++;
		}

		if (GameSt.hand[curPlyr][GameSt.handCount[curPlyr] - 2] != copper && GameSt.hand[curPlyr][GameSt.handCount[curPlyr] - 2] != silver && GameSt.hand[curPlyr][GameSt.handCount[curPlyr] - 2] != gold) {
			printf("Checking second card: Test failed.\n");
			failureSec++;
		}
		else {
			printf("Checking second card: Test passed.\n");
			successSec++;
		}

		printf("Adventurer card test ran %d times, with %d top card passes and %d top card fails.  And %d second card passes and %d second card fails.\n", testCnt, successTop, failureTop, successSec, failureSec);
	}

	return 0;
}