/* 
	|crazyEightsPlayer|
	Assignment 2
	By: Luv Kapur and Theo Dule
	crazyEightsPlayer.h
*/
#ifndef _CRAZYEIGHTSPLAYER_H_
#define _CRAZYEIGHTSPLAYER_H_

#include <iostream>
#include <vector>
#include "player.h"


class CrazyEightsPlayer : public Player{
public:
	bool checkHand(Card starter, std::vector<Card> &availableCards, std::vector<int> &id);
};
#endif