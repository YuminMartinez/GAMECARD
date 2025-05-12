#pragma once

#include "util.h"

class Player
{
	std::string id;
	std::vector<Suit>hand;

	Player();
	void InsertCard(Card card);
	Card GetCard(); const
	Card GetCard(const Suit& suit);
	void SortCards();

};


