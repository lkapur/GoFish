/* 
	|goFish|
	Assignment 2
	By: Luv Kapur and Theo Dule
	goFish.h
*/
#ifndef _GOFISH_H_
#define _GOFISH_H_
#include <iostream>
#include "goFishPlayer.h"
#include "game.h"
	
class GoFish : public Game {

	GoFishPlayer *players;
	static GoFish* goFish;
	int no_of_players;
	int opponent_id;
	GoFish();// Instantiate two players

public:
	static GoFish* get_GoFishInstance();
	// Deals Cards according to Game Type (7 for goFish) (8 for crazyEights)
	void dealHand(int cardsDelt);
	void playGame();
	bool askCard(int cardValue, int playerID, std::vector<Card>& addCards );
	std::string get_GameName();
	int playHand(int& player_id, int& choice);
};

#endif