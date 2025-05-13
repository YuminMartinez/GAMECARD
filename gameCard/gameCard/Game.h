#pragma once
#include "util.h"
class Game
{
private:
	int numPlayers;
	std::vector<Player> players;
	std::vector<Card> deck;
	std::vector<Card> discarded;
public:
	Game();
	Card GetNewCard();
	//void DiscardCard(const Card& card);
	//void PrintDiscarded() const;
	
};


