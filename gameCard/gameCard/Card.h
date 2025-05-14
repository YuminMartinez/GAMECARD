#pragma once
#include "util.h"

enum class Suit 
{
	CLUB,    
	SPADE,   
	DIAMOND, 
	HEART    
};



class Card
{
private:
	Suit m_suit;
	int m_value;

public:
	
	Card(Suit s, int v);
	int getValue() const;	
	bool operator==(const Card& other) const;
	Suit getSuit()const;
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};


int Card::getValue() const
{
	return m_value;
}


Suit Card::getSuit() const
{
	return m_suit;
}


