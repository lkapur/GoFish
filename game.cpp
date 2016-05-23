/*
	|Abstract Class|(Template Method Implementation)
	Assignment 2
	By: Luv Kapur and Theo Dule
	game.h
 */

#include "game.h"

#define DEBUG 1 // Set to 0 to disable debug

// Game Constructor
/*
    The Game Constructor instantiates the attributes which compose a game, 
    that are a deck and players. It also sets the player_id which basically decides
    who starts first, player id = 0 or 1 (Computer or Human)
*/
Game::Game(){
    deck = Deck::get_DeckInstance(); // Get Singleton instance
    player_id = choosePlayer(); // randomly choses a player_id to start the game
    players = NULL;
}

/* it starts the game with basic game functions which includes displaying the game title
    , shuffling the deck, printing out the shuffled deck

*/
void Game::startGame(){
    
    clear();
    displayGameTitle();
    deck->shuffle(); // Shuffle deck
    
    // Debug purposes (only if debug called)
    if(DEBUG){
        deck->print();
        std::cout << " \n> ";
        displayLines();
        std::cout << "> Shuffled Deck Displayed" << std::endl;
    }
    // Debug ends
}

// Handles Dynamic Game Title
void Game::displayGameTitle(){
    
    displayLines(); // call displayLines()
    std::cout<< std::right;
    
    //Handles displaying goFish or crazyEights depending on the object created and cosmetic look
    std::cout << "> " << std::setfill (' ') << std::setw (41) << this->get_GameName() << std::endl;
    std::cout << "> " << std::setfill ('-') << std::setw(76) << "-" << std::endl;
    
}

// Virtual function that can be overidden when derived
std::string Game::get_GameName(){
    return "Default";
}

// Handles cosmetic appearance of lines
void Game::displayLines(){
    std::cout << "> -" << std::setfill ('-') << std::setw(75) << "-" << std::endl;
}

// Deal number of cards according to game chosen
int Game::get_numberHandCards(){
    if(get_GameName() == "Crazy Eights")
        return 5;
    else
        return 7;
}

// Handles cosmetic appearance of lines
void Game::displayLines(int no_of_spaces){
    std::cout << "> -" << std::setfill ('-') << std::setw(no_of_spaces) << "-" << std::endl;
}

// Function handles screen clearing
void Game::clear(){
    if(system("clear"))system("CLS"); // Command Prompt and Terminal Compatible
}

void Game::pause(){
    std::cout << ">>> Press Enter to Continue ";
    std::cin.sync(); std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
// Randomly chooses Player or AI
int Game::choosePlayer(){
    return 0;
}

// switches the playter id and references back the chanegd id in its parameters, 
// that is if the player id is 1 it changes to 0 and vice versa
void Game::switchPlayer(int &player_id, int no_of_players) {

    if(player_id == (no_of_players - 1)) {
        player_id = 0;
    }
    else if(player_id == 0) {
        player_id = 1;
    }
    else if(player_id == 1) {
        player_id = 2;
    }
    else if(player_id == 2) {
        player_id = 3;
    }
}
