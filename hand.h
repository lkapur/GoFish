/*
	|Hand|
	Assignment 2
	By: Luv Kapur and Theo Dule
	hand.h
 */
#ifndef _HAND_H_
#define _HAND_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "card.h"

class Hand {
    
private:
    std::vector<Card> cards;
    int no_of_cards;
public:
    Hand();
    void addCard(Card add);
    std::vector<Card> showCards() const;
    int numberOfCards() const;
    Card getCard(int index);
    void removeCard(int index);
    void removeCards(std::vector<Card> rmCards);
};
#endif