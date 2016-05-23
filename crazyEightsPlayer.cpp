/* 
	|crazyEightsPlayer|
	Assignment 2
	By: Luv Kapur and Theo Dule
	crazyEightsPlayer.cpp
*/
#include "crazyEightsPlayer.h"
	
/*
	the check hand function checks the cards in the hand for the following possibilities :
	1. A Wild Card : A card whose value is 8
	2. If the cards in the hand matches either the value or the suit of the starter card
	3. Returns the available card which matches the (2) criteria listed above as a vector object
*/
bool CrazyEightsPlayer::checkHand(Card starter, std::vector<Card> &availableCards, std::vector<int> &id) {
	bool wildFlag = false;
	std::vector<Card> myCard = hand.showCards();
	for(int i = 0; i < myCard.size(); i++) {
			
		if(myCard[i].getValue() == 7)
			wildFlag = true;

		if(myCard[i].getValue() == starter.getValue() || myCard[i].getSuit() == starter.getSuit()) { 
			id.push_back(i+1);
			availableCards.push_back(myCard[i]);
		}

	}
	
	//std::cout << " checkHand() " << std::endl;
	if(availableCards.size() > 0 || wildFlag == true)
		return true;
	else
		return false;

}
