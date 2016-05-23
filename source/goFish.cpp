/*
	|goFish|
	Assignment 2
	By: Luv Kapur and Theo Dule
	goFish.h
 */
#include "goFish.h"
// Defines a static memeber variable
GoFish* GoFish::goFish = NULL;

// GoFish Constructor instantiates the GoFish object by creating DEFAULT 2 GoFish Players
GoFish::GoFish() {
    no_of_players = 2;
    opponent_id = 1;
} 

// Returns the singleton access to the GoFish Object
GoFish* GoFish::get_GoFishInstance(){
        if(goFish == NULL)
            goFish = new GoFish();

        return goFish;
}

// Deals Cards according to Game Type (7 for goFish) (8 for crazyEights)
// cardsDealt refers to the number of cards to be delt to both of the players
void GoFish::dealHand(int cardsDelt){
    clear();
    displayGameTitle();
    
    for(int j = 0; j < no_of_players; j++) {
        for(int i = 0; i < cardsDelt; i++) 
            players[j].set_playerHand(deck->deal());
    }
}


int GoFish::playHand(int& player_id, int& choice) {
    
    // check empty hand
    if(players[player_id].emptyHand()) {
    // if the hand is empty populate it with 7 cards
        for(int i = 0; i < 7; i++)
            players[player_id].set_playerHand(deck->deal());
    }

    if(player_id == 0) {

        // display the hand of the specified player
        players[player_id].showHand();
        displayLines(54);

        do {
            // ask which player you want to ask
            std::cout << ">> Q. Which player do you want to ask ? (id = ";
            for(int i = 1; i < no_of_players; i++)
                std::cout << i << ",";
            std::cout <<  "..). "<< std::endl;
            for(int i = 1; i < no_of_players; i++) {
                std::cout << "<<    " << i <<". " << players[i].get_playerName() << std::endl;
            }
            std::cout << ">  Player ID : ";
            std::cin >> opponent_id;
        }while(opponent_id < 0 || opponent_id > no_of_players);

        displayLines();
        // prompt the user for the card they want to play
        std::cout << ">> Q. What rank do you want to ask "
        << players[opponent_id].get_playerName() << " for? (rank = 1,2,3...). ";
        std::cin >> choice;
        std::cin.ignore(3000,'\n');
    }
    else {
        // pick a random card from the hand
        choice = (rand() + time(0)) % (players[player_id].get_playerHandCount()+1);
    }

    // get the card value of the specified choice (either by direct input for a player or randomly for the Bot)
    return players[player_id].getCardValue(--choice);;
}

// starts the actual gameplay with game-specific (GoFish) rules
void GoFish::playGame(){
    
    int cv, choice;
    std::vector<Card> myCards;
    
    do {
        std::cout << "> How many players are playing ? (Max. 4)" << std::endl;
        std::cout << ">> Number of Players : ";
        std::cin >> no_of_players;
    }while(no_of_players < 1 || no_of_players > 4);

    // set number of players
    players = new GoFishPlayer[no_of_players];

    // Player info
    players[player_id].set_playerName(); // Set player name
    for(int i = 1; i < no_of_players; i++)
        players[i].set_defaultPlayerName(i);

    dealHand(get_numberHandCards()); // Deals cards

    // GoFish win condition - if any player scores the first book, that is Four of a kind
    while(players[player_id].noOfBooks() < 1) {
        
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /*********************************************************
         *                   Initial Move                        *          
         *********************************************************
         *           1. Select a card from hand                  *
         *           2. Ask the other player for that card       *
         *                                                       *
         ********************************************************/

        // play the card from your hand - human or computer | return the chosen card value
        cv = playHand(player_id, choice);
        //std::cout << "choice == " << choice;
        std::cout << "<< " << players[player_id].get_playerName() << " asks ";
        std::cout << players[opponent_id].get_playerName() << " for" ;
        bool res = askCard(cv,opponent_id, myCards);
        std::cout << players[player_id].getCardByIndex(choice) << std::endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /*********************************************************
         *                 Second Move Check                     *          
         *********************************************************
         *           1. Check if the other player has card       *
         ********************************************************/
            
        if(res) {

        /*********************************************************
         *            If Yes, Add cards to your hand             *                                              
         ********************************************************/

            std::cout << "<< " << players[opponent_id].get_playerName() << " gives ";
            // add the card 
            players[player_id].addCards(myCards);
            std::cout << players[player_id].get_playerName() << " ";
            for(int i = 0; i < myCards.size(); i++)
                std::cout << myCards[i].print() <<" ";    
            std::cout << std::endl;
            if(players[player_id].checkHand()) {
                players[player_id].booksScored();
                break;
            }
        }
        else {
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

           /*********************************************************
            *              If No, Say go fish                       *
            ********************************************************/

            std::cout << "<< " << players[opponent_id].get_playerName() <<" says Go Fish!!!" << std::endl;
            std::cout << "<< " << players[player_id].get_playerName() <<" draws a card from the deck" << std::endl;
            Card withdraw = deck->deal();
            players[player_id].set_playerHand(withdraw);
            

            if(players[player_id].checkHand()) {
                    players[player_id].booksScored();
                    break;
            }
            
            if(withdraw.getValue() != players[player_id].getCardValue(choice)) {
                switchPlayer(player_id, no_of_players);
                switchPlayer(opponent_id, no_of_players);
            }
            else
                std::cout << "<< " << players[player_id].get_playerName() <<" gets" << withdraw.print() << std::endl; 
        }    
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      /*********************************************************
       *                  Declare Winner                       *
       ********************************************************/
    if(players[0].noOfBooks() == 1)
        std::cout << "<<< YOU WIN!!!" << std::endl;
    else if(players[1].noOfBooks() == 1)
        std::cout << "<<< BOT 1 WINS!!! " << std::endl;
    else if(players[2].noOfBooks() == 1)
        std::cout << "<<< BOT 2 WINS!!! " << std::endl;
    else if(players[3].noOfBooks() == 1)
        std::cout << "<<< BOT 3 WINS!!! " << std::endl;

}

bool GoFish::askCard(int cardValue, int playerID, std::vector<Card>& addCards ) {
    if(players[playerID].checkCard(cardValue)) {
        addCards = players[playerID].giveCards(cardValue);
        return true;
    }
    else 
        return false;
}

std::string GoFish::get_GameName(){return "Go Fish";}
