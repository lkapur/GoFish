/*
	|crazyEights|
	Assignment 2
	By: Luv Kapur and Theo Dule
	crazyEights.cpp
 */
#include "crazyEights.h"
// Defines a static memeber variable with an initial value
CrazyEights* CrazyEights::crazyEights = NULL;

// Crazy Eights Constructor - initializes the crazy eight players
CrazyEights::CrazyEights() {players = new CrazyEightsPlayer[2];} // Instantiate two players

// returns the singleton access to the crazy eights object
CrazyEights* CrazyEights::get_CrazyEightsInstance(){
        if(crazyEights == NULL)
            crazyEights = new CrazyEights();

        return crazyEights;
}

// Deals Cards according to Game Type (7 for goFish)(5 for crazyEights)
void CrazyEights::dealHand(int cardsDelt) {
    clear();
    displayGameTitle();
    
    for(int i = 0; i < cardsDelt; i++) {
        players[0].set_playerHand(deck->deal());
        players[1].set_playerHand(deck->deal());
    }
}
// starts the Crazy Eights game with specific rules
void CrazyEights::playGame() {
    int choice, count = 0;
    std::vector<Card> availableCards;
    bool flag = false;
    
    players[0].set_playerName(); // Set player name
    
    
    dealHand(get_numberHandCards()); // Deals cards
    // The dealer turns up the top card and places it in a separate pile; this card is the “starter.”
    // If an eight is turned, it is buried in the middle of the pack and the next card is turned.
    do {
        starter = deck->deal(); // The top most card of the deck is the pile card
        if(starter.getValue() == 7) {
            deck->addCard(starter);
            deck->shuffle();
            flag = true;
        }
        else
            flag = false;
    
    }while(flag);
    
    // If the deck is empty, the game ends
    while(deck->remainingCards()!=0){
        std::vector<int> id;
        // display pile card
        std::cout << ">> Starter Card : " << starter.print() << std::endl;
        displayLines();
        flag = false;
        // if the number of cards in the hand for Human is 0, the game ends | Human Wins!!!
        if(player_id == 0){
            if(players[0].get_playerHandCount() == 0) {
                players[0].setWin(true);
                break;
            }

            players[player_id].showHand();
            displayLines(52);
            id.clear();
            availableCards.clear();
            // checks if a move is possible otherwise draw a card
            if(players[player_id].checkHand(starter, availableCards, id)) {
                do {
                    // prompts the user for input
                    std::cout << ">> Q. What rank do you want to play (rank = 1,2,3...). ";
                    std::cin >> choice;
                    std::cin.ignore(2000,'\n');
                    // checks for a wild card with user input choice
                    if(checkWildCard(choice)) {
                        int suit_choice;
                        do{
                            std::cout << ">> ** Wild Card Mode ON ** ¯\\_(ツ)_/¯" << std::endl;
                            std::cout << ">> What suit do you want to change the starter card to? (1), (2), (3), (4)" << std::endl;
                            std::cout << ">> 1. Hearts " << std::endl;
                            std::cout << ">> 2. Diamonds " << std::endl;
                            std::cout << ">> 3. Clubs " << std::endl;
                            std::cout << ">> 4. Spades " << std::endl;
                            displayLines(52);
                            std::cin >> suit_choice;
                            // input validation 
                            if(suit_choice < 1 || suit_choice > 4)
                                std::cout << "<<< Wrong Choice. Enter (1), (2), (3) or (4) " << std::endl;
                            else {
                                std::string suit;
                                std::cout << "<< Starter Card : Suit Changed From " << starter.getSuit();
                                switch (choice) {
                                    case 1 :
                                        suit = "Hearts";
                                        break;
                                    case 2 :
                                        suit = "Diamonds";
                                        break;
                                    case 3 :
                                        suit = "Clubs";
                                        break;
                                    case 4 :
                                        suit = "Spades";
                                        break;
                                }
                                // changes the suit of the wild card
                                starter.changeSuit(suit);
                                // removes the wild card from the players hand
                                players[0].removeCardByIndex(choice-1);
                                std::cout << " to " << starter.getSuit() << std::endl;
                                break;
                            }
                        }while(true);
                    }
                    else { // if the choice is not a wild card
                        Hand myHand = players[0].getHand();
                        std::vector<Card> myCards = myHand.showCards();
                        // checks if the move played is correct or not
                        if(myCards[choice-1].getValue() != starter.getValue() && myCards[choice-1].getSuit() != starter.getSuit()) {
                            std::cout << ">>> Wrong Option : Possible Moves are - " << std::endl;
                            displayLines(52);
                            // if wrong move played , prompts the user with correct options
                            for(int i = 0; i < availableCards.size(); i++)
                                std::cout << "> |" <<" "<< id[i] <<".  |" << std::setfill(' ') << std::setw(26) << std::right << availableCards[i].print() << std::setfill(' ') << std::setw(20) << std::right << "|" << std::endl;
                            
                            std::cout << "> " << std::setfill ('-') << std::setw(52) << "-" << std::endl;
                            flag = true;
                        }
                        else { // if correct move played changes the starter card and removes the card from the hand
                            starter = myCards[choice - 1];
                            players[0].removeCardByIndex(choice- 1);
                            flag = false;
                        }
                    }
                }while(flag);
            }
            else { // if no possible moves draw a card
                std::cout << ">> No Possible Moves - Drawing a Card " << std::endl;
                players[0].set_playerHand(deck->deal()); // if cannot play draw a card
            }
            switchPlayer(player_id,2); // switch the player
        }
        else { // if the number of cards in computers hand is 0 | Computer Wins !!!!
            if(players[1].get_playerHandCount() == 0) {
                players[1].setWin(true);
                break;
            }
            Hand myHand = players[1].getHand();
            std::vector<Card> myCards = myHand.showCards();
            availableCards.clear(); // checks the computer hand for a correct move
            if(players[player_id].checkHand(starter,availableCards,id)) {
                choice = spitAIMove(availableCards); // spit AI move
                std::cout << ">> COMPUTER plays" << myCards[choice].print() << std::endl;
                starter = myCards[choice];
                players[1].removeCardByIndex(choice); // remove card from hand
                availableCards.clear();
            }
            else { // if no possible moves
                std::cout << ">> COMPUTER - No Possible Moves - Drawing a Card " << std::endl;
                players[1].set_playerHand(deck->deal()); // if cannot play draw a card
            }
            switchPlayer(player_id,2);
        }
        
    }
    
    if(players[0].getWin())
        std::cout << "<<< YOU WIN!!!" << std::endl;
    else if(players[1].getWin())
        std::cout << "<<< COMPUTER WINS !!!" << std::endl;
}

// checks the AI Hand and sees which is the best move
int CrazyEights::spitAIMove(std::vector<Card> availableCards) {
    
    int counter = 0;
    
    Hand myHand = players[1].getHand();
    std::vector<Card> myCards = myHand.showCards();
    for(int i = 0; i < availableCards.size(); i++) {
        for(int j = 0; j < myCards.size(); j++) {
            if(availableCards[i].getValue() == myCards[j].getValue() && availableCards[i].getSuit() == myCards[j].getSuit())
                return j;
        }
    }
    return 0;
}

// checks for a wild card with user specified input choice of card from his hand
bool CrazyEights::checkWildCard(int choice) {
    Hand myHand = players[0].getHand();
    std::vector<Card> myCards = myHand.showCards();
    if(myCards[choice-1].getValue() == 7)
        return true;
    else
        return false;
}

// returns the game name
std::string CrazyEights::get_GameName() {return "Crazy Eights";}
