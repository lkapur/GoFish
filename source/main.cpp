/* 
	|Main|
	Assignment 2
	By: Luv Kapur and Theo Dule
	main.cpp
*/
#include <iostream>
#include <ctype.h>
#include "gameFactory.h"	
/*
	The main function initiates the program by calling the GameFactory class for a specific game object
	requested by the user. 
*/

int main(){

	int choice; // user choice
	GameFactory *gameSelector = GameFactory::get_GameFactoryInstance();  // get the GameFactory singleton instance
	Game *game = NULL;  // GameFactory returns a game object

	do {
		//Game menu 
		game->clear();
		game->displayLines();
		std::cout<< std::right;
		std::cout << "> " << std::setfill (' ') << std::setw (49) << "Theo & Luv's Card Game Factory" << std::endl;
		game->displayLines();

		std::cout << "> What Game would you like to play? (1) or (2)" << std::endl;
		std::cout << "> 1. Go Fish" << std::endl;
		std::cout << "> 2. Exit" << std::endl;
		game->displayLines();
		std::cout << ">> Please enter your choice : ";
		std::cin >> choice;

		// Basic input validation 
		if(choice == 2)
			exit(0);
		else if(choice == 1) {
			game = gameSelector->gameChoice(choice); // Pass player choice to gameFactory Function
			game->startGame();
			game->playGame();
			GameFactory::reset_GameFactoryInstance();
			game->displayLines();
			game->pause();
			exit(0);
		}
		else {
			std::cout << ">>> Please a valid choice of either (1) or (2)" << std::endl;
			game->pause();
		}
	} while(choice != 1 || choice != 2);

	return 0;
}