/* 
	|goFishPlayer|
	Assignment 2
	By: Luv Kapur and Theo Dule
	goFishPlayer.h
*/
#ifndef _GOFISHPLAYER_H_
#define _GOFISHPLAYER_H_
#include "player.h"
#include <vector>
#include <iomanip>
#include <iostream>
	
class GoFishPlayer : public Player {

private:
	std::vector <int> books;
	int no_of_books;

public:
	GoFishPlayer();
	int noOfBooks();
	void booksScored();	
	bool checkHand();
};
#endif