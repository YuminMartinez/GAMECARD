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
private:
	Suit m_suit;
	int m_value;

public:
	
	Card(Suit s, int v);
	int getValue();	
	bool operator==(const Card& other) const;
	Suit getSuit()const;
};


int Card ::getValue()
{
	return m_value;
}


Suit Card::getSuit() const
{
	return m_suit;
}


