/* 
	|crazyEights|
	Assignment 2
	By: Luv Kapur and Theo Dule
	crazyEights.h
*/
#ifndef _CRAZYEIGHTS_H_
#define _CRAZYEIGHTS_H_
#include <iostream>
#include "crazyEightsPlayer.h"
#include "game.h"
#include "card.h"
#include <vector>
	
class CrazyEights : public Game{

	CrazyEightsPlayer *players;
	Card starter;
	static CrazyEights* crazyEights;
	CrazyEights(); // Instantiate two players

public:
	static CrazyEights* get_CrazyEightsInstance();
	// Deals Cards according to Game Type (7 for goFish)(5 for crazyEights)
	void dealHand(int cardsDelt);

	void playGame();

	int spitAIMove(std::vector<Card> availableCards);

	bool checkWildCard(int choice);

	std::string get_GameName();

};
#endif