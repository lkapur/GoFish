/*
	|Deck|
	Assignment 2
	By: Luv Kapur and Theo Dule
	deck.cpp
 */


#include "deck.h"
// Defines a static memeber variable
Deck* Deck::deck = NULL;
const int CARDS_PER_DECK = 52; // Deck size is constant

// returns the singleton access to a deck
Deck* Deck::get_DeckInstance(){
    // checks if the deck exists or not, if doesn't creates one
        if(deck == NULL)
            deck = new Deck();
        
        return deck;
}

// deck constructor - initializes the deck with 52 cards
Deck::Deck(){
    cards = new Card[CARDS_PER_DECK];
    cards_used = CARDS_PER_DECK;
    current_card = 0;
    
    std::string faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King"};
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    for(int i = 0; i < CARDS_PER_DECK; i++)
        cards[i] = Card(faces[i%13], suits[i/13]);  // populates a deck in order
    
}

// Shuffles the Created Deck
void Deck::shuffle(){
    
    current_card = 0;
    // replace the every card starting from 0th position to the last with a randomly generated card position from the deck (0-51)
    for(int first = 0; first < CARDS_PER_DECK; first++) {
        
        int second = (rand() + time(0)) % CARDS_PER_DECK;
        Card temp = cards[first];
        cards[first] = cards[second];
        cards[second] = temp;
    }
}

// checks the position of the current card and returns back the card from the deck
/* makes sure that after the current card completes one deck cycle, that is its position
    is the same from where it started, it shuffles the deck so that the deal doesn't return the same cards
*/
Card Deck::deal(){
    
    if(current_card < CARDS_PER_DECK) 
        return (cards[current_card++]);
    
    if(current_card > CARDS_PER_DECK)
        shuffle();
    
    return cards[0];
}
// returns the remaining cards in the deck
int Deck::remainingCards(){ return CARDS_PER_DECK - current_card;}
// takes a card as a parameter and adds it to the deck
void Deck::addCard(Card add) {cards[--current_card] = add;}
// prints the deck in four per line
void Deck::print() const{
    
    std::cout<<std::left;
    
    for(int i = 0; i < CARDS_PER_DECK; i++) {
        std::cout << "< " << std::setfill(' ') << std::setw(19) << cards[i].print();
        // prints four cards per line
        if((i+1) % 4 == 0)
            std::cout<<std::endl;
    }
    
}
