#include "util.h"

int main() 
{
    Game game;

    game.DiscardCard(Card(Suit::HEART, 10));
    game.PrintDiscarded(); 

    return 0;
}