/*
	|Card|
	Assignment 2
	By: Luv Kapur and Theo Dule
	card.h
 */

#ifndef _CARD_H_
#define _CARD_H_
#include <string>

class Card {
    
private:
    std::string face;
    std::string suit;
    int value;
    
public:
    
    // Default Constructor
    Card(){}
    
    // Constructor for Card Assignment
    Card(std::string cardFace,std::string cardSuit);
    std::string print() const; // Print Assigned Card
    int getValue() const;// Returns Card Denominations
    std::string getSuit() const; // Return Card Suit
    std::string getFace() const; // Return Face
    void changeSuit(std::string _suit);
    
};
#endif