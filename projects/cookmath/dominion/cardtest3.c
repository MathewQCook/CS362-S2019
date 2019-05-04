/*
Name: Mathew Cook
Course: CS362
Assignment 3

Unit Testing for salvager card Function
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

	//Check player 1's initial number of buys and coins
	int preBuys = GameSt.numBuys;
	int preCoins = GameSt.coins;

	//Trigger the salvagerCard function via cardEffect function
	cardEffect(salvager, 1, 0, 0, &GameSt, 0, 0);

	//Check player 1's number of buys and coins post card being played
	int postBuys = GameSt.numBuys;
	int postCoins = GameSt.coins;
	int buysDif = postBuys - preBuys;
	int coinsDif = postCoins - preCoins;

	assert(buysDif == 1);
	printf("Increase to number of buys test passed.\n");

	assert(coinsDif > 0);
	printf("Increase coins test passed.\n");

	//Restarting the game to test direct call of salvager function
	initializeGame(2, k, 100, &GameSt);

	//Check player 1's initial number of buys and coins
	preBuys = GameSt.numBuys;
	preCoins = GameSt.coins;

	//Trigger the salvagerCard function via cardEffect function
	salvagerCard(0, &GameSt, 0, 1);

	//Check player 1's number of buys and coins post card being played
	postBuys = GameSt.numBuys;
	postCoins = GameSt.coins;
	buysDif = postBuys - preBuys;
	coinsDif = postCoins - preCoins;

	assert(buysDif == 1);
	printf("Increase to number of buys test passed.\n");

	assert(coinsDif > 0);
	printf("Increase coins test passed.\n");

	printf("salvagerCard test complete.\n");

	return 0;
}