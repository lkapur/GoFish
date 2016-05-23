/*
	|Player|
	Assignment 2
	By: Luv Kapur and Theo Dule
	player.cpp
 */
#include "player.h"

// Constructor
Player::Player(){
    playerName = "Computer"; // Sets default AI name to Computer
    hand = Hand(); // Instatiate the hand object
    win = false; // by default the player loses
}
// sets the win factor for a player
void Player::setWin(bool result) {win = result;}
// returns the win factor
bool Player::getWin(){return win;}
// virtual fucntion checkhand which by default returns true, overridden by the game which inherits it
bool Player::checkHand(){return true;}
// checks if the hand is empty or not
bool Player::emptyHand() const {
    if(this->hand.numberOfCards() == 0)
        return true;
    else
        return false;
}
// returns selected card of user specified card value
std::vector<Card> Player::getSelectedCards(int cardValue) {
    
    std::vector<Card> myCard = hand.showCards();
    std::vector<Card> cardTemp;
    
    for(int i =0; i < myCard.size(); i++) {
        if(myCard[i].getValue() == cardValue)
            cardTemp.push_back(myCard[i]);
    }
    return cardTemp;
}
// returns the selected cards
std::vector<Card> Player::giveCards(int cardValue) {
    
    std::vector<Card> cardsToGive = this->getSelectedCards(cardValue);
    hand.removeCards(cardsToGive);
    return cardsToGive;
}
// adds the specified list of cards to the hand
void Player::addCards(std::vector<Card> addCards) {
    
    for(int i = 0; i < addCards.size(); i++) {
        hand.addCard(addCards[i]);
    }
}
// checks if the card value specified matches any card in the hand
bool Player::checkCard(int cardValue) {
    std::vector<Card> myCard = hand.showCards();
    
    for(int i = 0; i < myCard.size(); i++) {
        if(myCard[i].getValue() == cardValue )
            return true;
    }
    return false;
}
// removes card by specified index value
void Player::removeCardByIndex(int index) {hand.removeCard(index);}
// returns the card asked by a specific index
std::string Player::getCardByIndex(int cardIndex) {return this->hand.getCard(cardIndex).print();}
// returns the current hand object for the current player
Hand Player::getHand() { return hand;}

// Get Player Name
std::string Player::get_playerName() const{ return playerName; }

// Set Player Name
void Player::set_playerName(){
    
    //displayLines(30);
    std::cout << ">> Enter your player name" << " : ";
    std::cin >> this->playerName;
}

void Player::set_defaultPlayerName(int i){ this->playerName = "Bot " + std::to_string(i);}
// Set Player Hand
void Player::set_playerHand(Card card){
    hand.addCard(card); // Populate player hand
}
// returns the number of cards in the hand of the player
int Player::get_playerHandCount() const{ return hand.numberOfCards(); }

// displays the cards in the hand
void Player::showHand() const {
    
    std::cout <<  "<" << std::endl <<"< |" << std::setfill(' ') << std::setw(29) << std::right << this->get_playerName() << std::setfill(' ') << std::setw(25) << std::right << "|" << std::endl;
    std::cout << "< " << std::setfill ('-') << std::setw(54) << "-" << std::endl;
    
    std::vector <Card> myCard = hand.showCards();
    
    for(int i = 0; i < myCard.size(); i++) {
        std::cout << "< |" <<" "<< i+1 <<".  |" << std::setfill(' ') << std::setw(28) << std::right << myCard[i].print() << std::setfill(' ') << std::setw(20) << std::right << "|" << std::endl;
    }
}

// returns the card value for a specific card in the hand
int Player::getCardValue(int index) {
    Card br = hand.getCard(index);
    return br.getValue();
}