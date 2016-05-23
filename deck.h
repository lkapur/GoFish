/*
	|Deck|
	Assignment 2
	By: Luv Kapur and Theo Dule
	deck.h
 */

#ifndef _DECK_H_
#define _DECK_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "card.h"

class Deck {
    
private:
    Card *cards;
    int cards_used;
    int current_card;
    
    static Deck *deck;
    
    // Create Deck of 52 cards
    Deck();
    
public:
    
    // Shuffles the Created Deck
    void shuffle();
    
    Card deal();
    int remainingCards();
    
    void addCard(Card add) ;
    
    void print() const;
    // Check for instance of Deck (Singleton Access)
    static Deck* get_DeckInstance();
    //Destructor
    ~Deck(){}
};
#endif