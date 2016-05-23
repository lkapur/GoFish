/* 
	|goFishPlayer|
	Assignment 2
	By: Luv Kapur and Theo Dule
	goFishPlayer.h
*/
#include "goFishPlayer.h"

GoFishPlayer::GoFishPlayer() {
		no_of_books = 0;
		books.resize(13);
}

int GoFishPlayer::noOfBooks(){return no_of_books;}

void GoFishPlayer::booksScored() {no_of_books++;}
	
bool GoFishPlayer::checkHand() {
	std::vector <Card> myCard = hand.showCards();

	std::fill(books.begin(), books.end(), 0);
	for(int i = 0; i < myCard.size(); i++) 
		books[myCard[i].getValue()] = books[myCard[i].getValue()] + 1;

	int pos = std::find(books.begin(), books.end(), 4) - books.begin();
	 
	if(pos != 13) {

		std::cout << std::setfill ('-') << std::setw(54) << "-" << std::endl;
	 	std::cout << std::setfill (' ') << std::setw(30) << " Book Scored" << std::endl;
	 	std::cout << std::setfill ('-') << std::setw(54) << "-" << std::endl;
	 	for(int i = 0; i < myCard.size(); i++) {
	 		if(myCard[i].getValue() == pos)
				std::cout << "> |" <<" "<< i+1 <<".  |" << std::setfill(' ') << std::setw(26) << std::right << myCard[i].print() << std::setfill(' ') << std::setw(20) << std::right << "|" << std::endl;
		}	
		std::cout << "> " << std::setfill ('-') << std::setw(52) << "-" << std::endl;
		return true;
	}
	else 
		return false;
}
