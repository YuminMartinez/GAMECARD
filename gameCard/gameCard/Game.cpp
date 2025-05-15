
#include "util.h"
Game::Game()
{
	do
	{
		std::cout << "num of players? (min 2 , max 8) : ";

		std::cin >> numPlayers;

	} while (numPlayers < 2 || numPlayers > 8);



	players.reserve(numPlayers);

	// Inicializar deck con todas las cartas
	for (int s = static_cast<int>(Suit::CLUB); s <= static_cast<int>(Suit::HEART); ++s) {
		for (int v = 1; v <= 13; ++v) {
			deck.emplace_back(static_cast<Suit>(s), v); // Inicializar deck con todas las cartas
		}
	}
	std::random_shuffle(deck.begin(), deck.end());


	std::vector<std::string> names = { "Eric", "Sebastian", "Carol", "Yumin", "Roma", "Edgar", "Irene", "Xavi" };
	for (int i = 0; i < numPlayers; ++i) {
		players.emplace_back(names[i % names.size()]);
	}

	for (int i = 0; i < numPlayers; ++i) {
		for (auto& player : players) {
			player.InsertCard(GetNewCard());
		}
	}


}

void Game::DiscardCard(const Card& card) {
	discarded.push_back(card);
}

void Game::PrintDiscarded() const {
	if (!discarded.empty()) {
		std::cout << "Última carta descartada: " << discarded.back() << std::endl;
	}
}

Card Game::GetNewCard() {
	Card top = deck.back();
	deck.pop_back();
	return top;
}
