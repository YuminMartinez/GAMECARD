
#include "util.h"
Game::Game()
{
	do
	{
		std::cout << "num of players? (min 2 , max 8) : ";

		std::cin >> numPlayers;

	} while (numPlayers < 2 || numPlayers > 8);


	players.reserve(numPlayers);

	std::vector<std::string> names = { "Alice", "Bob", "Carol", "Dave", "Eve", "Frank", "Grace", "Hank" };
	for (int i = 0; i < numPlayers; ++i) {
		players.emplace_back(names[i % names.size()]);
	}

	for (int i = 0; i < 10; ++i) {
		for (auto& player : players) {
			player.InsertCard(GetNewCard());
		}
	}




}

Card Game::GetNewCard() {
	Card top = deck.back();
	deck.pop_back();
	return top;
}
