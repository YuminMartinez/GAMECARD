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
	void DiscardCard(const Card& card);
	void PrintDiscarded() const;
	
};


Game::Game()
{
	do
	{
		std::cout << "num of players? (min 2 , max 8) : ";

		std::cin >> numPlayers;

	}while (numPlayers < 2 || numPlayers > 8);


	players.reserve(numPlayers);

	std::vector<std::string> names = { "Alice", "Bob", "Carol", "Dave", "Eve", "Frank", "Grace", "Hank" };
	for (int i = 0; i < numPlayers; ++i) {
		players.emplace_back(names[i % names.size()]);
	}


	
}