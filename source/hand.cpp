/*
	|Hand|
	Assignment 2
	By: Luv Kapur and Theo Dule
	hand.h
 */
#include "hand.h"

Hand::Hand(){ no_of_cards = cards.size(); }
void Hand::addCard(Card add){ cards.push_back(add); }
std::vector<Card> Hand::showCards() const{ return cards; }
int Hand::numberOfCards() const{ return cards.size(); }
Card Hand::getCard(int index){ return cards[index]; }
void Hand::removeCard(int index) {cards.erase(cards.begin()+index);}
// removes the provided list of cards from the hand
void Hand::removeCards(std::vector<Card> rmCards){
    for(int j = 0; j < rmCards.size(); j++) {
        
        for(int i = 0; i < cards.size(); i++) {
            if(rmCards[j].getValue() == cards[i].getValue()) {
                cards.erase(cards.begin()+i);
            }
        }
    }
}
