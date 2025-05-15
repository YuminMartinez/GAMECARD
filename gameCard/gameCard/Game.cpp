
#include "util.h"
Game::Game()
{
	do
	{
		std::cout << "num of players? (min 2 , max 8) : ";

		std::cin >> numPlayers;

	} while (numPlayers < 2 || numPlayers > 8);



	players.reserve(numPlayers);

	// Inicializar deck temp con todas las cartas
	std::vector<Card> tempDeck;
	for (int s = static_cast<int>(Suit::CLUB); s <= static_cast<int>(Suit::HEART); ++s) {
		for (int v = 1; v <= 13; ++v) {
			tempDeck.emplace_back(static_cast<Suit>(s), v);
		}
	}

	// Insertar cartas en el stack en orden aleatorio
	srand(time(NULL)); 
	while (!tempDeck.empty()) 
	{
		int randomIndex = rand() % tempDeck.size();

		deck.push(tempDeck[randomIndex]); // Insertar carta aleatoria
		tempDeck.erase(tempDeck.begin() + randomIndex); // Eliminar del vector
	}


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
	Card top = deck.top();
	deck.pop();
	return top;
}
