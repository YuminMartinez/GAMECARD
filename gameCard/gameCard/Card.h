#pragma once
#include "util.h"
enum class Suit
{
	HEART,
	DIAMOND,
	SPADE,
	CLUB

};


class Card
{
	int value;
	void Card();
};


bool operator ==(const Card & card1, const Card& card2)
{
	std::cout << "Comparing enemies" << std::endl;
	return  card1 == card2;
}


