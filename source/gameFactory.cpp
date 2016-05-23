/*
	|Factory|
	Assignment 2
	By: Luv Kapur and Theo Dule
	gameFactory.h
 */
// Factory Deciding Function

#include "gameFactory.h"
// Defines a static memeber variable
GameFactory* GameFactory::gameFactory = NULL;

// Selects the appropriate game according to the user specified choice sent in the parameters
Game* GameFactory::gameChoice(int choice){
    
    if(choice == 1)
        game = GoFish::get_GoFishInstance(); // Player chooses goFish (Singleton) of Class GoFish
    else
        game = CrazyEights::get_CrazyEightsInstance(); // Player chooses crazyEights (Singleton) of Class CrazyEights
    
    return game; // return instance of game
}

// Singleton function for Game Factory Access
GameFactory* GameFactory::get_GameFactoryInstance(){
    	if(!gameFactory)
        	gameFactory = new GameFactory();
    
    	return gameFactory; // return access to object
}

// If Singleton is to be subclassed, then the destructor should be virtually declared
void GameFactory::reset_GameFactoryInstance(){
		delete gameFactory;
    	gameFactory = NULL;
}


