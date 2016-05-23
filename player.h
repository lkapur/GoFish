/* 
	|Player|
	Assignment 2
	By: Luv Kapur and Theo Dule
	player.cpp
*/
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <vector>
#include <iomanip>
#include "hand.h"

class Player{

protected:
	std::string playerName;
	Hand hand;
	bool win;

public:
	// Constructor
	Player();

	void setWin(bool result);

	bool getWin();

	virtual bool checkHand();

	bool emptyHand() const;

	virtual std::vector<Card> getSelectedCards(int cardValue);

	virtual std::vector<Card> giveCards(int cardValue);

	virtual void addCards(std::vector<Card> addCards);

	virtual	bool checkCard(int cardValue);

	void removeCardByIndex(int index);

	std::string getCardByIndex(int cardIndex);
	
	void set_defaultPlayerName(int i);

	Hand getHand();

	// Get Player Name
	std::string get_playerName() const;

	// Set Player Name
	void set_playerName();
	// Set Player Hand
	void set_playerHand(Card card);

	int get_playerHandCount() const;

	virtual void showHand() const;

	int getCardValue(int index);
};
#endif