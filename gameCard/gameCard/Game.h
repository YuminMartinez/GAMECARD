#pragma once
#include "util.h"
class Game
{
	int numberOfPlayers = 0;
	int players[numberOfPlayers];
	int deck;
	int discarted;

	Game();
};


Game::Game()
{
	std::cout << "num of players? (min 2 , max 8) : ";




}