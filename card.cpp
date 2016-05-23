/*
	|Card|
	Assignment 2
	By: Luv Kapur and Theo Dule
	card.cpp
 */
#include "card.h"
    
// Constructor for Card Assignment
/*
    Initializes the Card object with the specified face and suit value
*/
Card::Card(std::string cardFace,std::string cardSuit){
    face = cardFace;
    suit = cardSuit;
    
    if(face == "Ace")
        value = 0;
    else if(face == "Deuce")
        value = 1;
    else if(face == "Three")
        value = 2;
    else if(face ==  "Four")
        value = 3;
    else if(face == "Five")
        value = 4;
    else if(face == "Six")
        value = 5;
    else if(face == "Seven")
        value = 6;
    else if(face == "Eight")
        value = 7;
    else if(face ==  "Nine")
        value = 8;
    else if(face ==  "Ten")
        value = 9;
    else if(face ==  "Jack")
        value = 10;
    else if(face ==  "Queen")
        value = 11;
    else if(face ==  "King")
        value = 12;
}
// prints the Card with its attributes, face and a suit
std::string Card::print() const{ return ( + " " + face + " of " + suit); } // Print Assigned Card
// returns the card value
int Card::getValue() const{ return value; }
// returns the card suit
std::string Card::getSuit() const{ return suit; } 
 // Return Face
std::string Card::getFace() const{return face;}
// change the suit of a specific card 
void Card::changeSuit(std::string _suit) {suit = _suit;}
