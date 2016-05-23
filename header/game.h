/* 
	|Abstract Class|(Template Method Implementation)
	Assignment 2
	By: Luv Kapur and Theo Dule
	game.h
*/
#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include "deck.h"
#include "player.h"
#include <limits>

// Abstract Class Game - which forms the foundation for both the games - GoFIsh and CrazyEights
class Game {

protected:
	// A Game is composed of a deck and players
	Deck* deck;
	Player* players;
	int player_id;

public:
	// Game Constructor
	Game();

	void startGame();
	virtual void playGame() = 0;
	// Deals Cards according to Game Type (7 for goFish) (8 for crazyEights)
	virtual void dealHand(int cardsDelt) = 0;
	// Handles Dynamic Game Title
	void displayGameTitle();
	// Virtual function that can be overidden when derived
	virtual std::string get_GameName();

	// Handles cosmetic appearance of lines
	void displayLines();

	// Deal number of cards according to game chosen
	int get_numberHandCards();

	// Handles cosmetic appearance of lines
	void displayLines(int no_of_spaces);
	
	// Function handles screen clearing
	void clear();

	void pause();
	// Randomly chooses Player or AI
	int choosePlayer();

	void switchPlayer(int &player_id, int no_of_players);
};
#endif