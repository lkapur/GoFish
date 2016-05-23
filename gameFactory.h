/* 
	|Factory|
	Assignment 2
	By: Luv Kapur and Theo Dule
	gameFactory.h
*/
#ifndef _GAMEFACTORY_H_
#define _GAMEFACTORY_H_
#include "game.h"
#include "goFish.h"
#include "crazyEights.h"
	
class GameFactory {
private:
	
	Game *game; // Declares an instance of a Game (goFish or crazyEights)
	// private static pointer to the GameFactory class - can only be initialized by calling the get_GameFactoryInstance() function
	static GameFactory *gameFactory; 

public:
	// Factory Deciding Function
	Game* gameChoice(int choice);
	static GameFactory* get_GameFactoryInstance();
	static void reset_GameFactoryInstance();
	
};

#endif
