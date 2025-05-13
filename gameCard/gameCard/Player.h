#pragma once

#include "util.h"

class Player
{
private:
	std::string id;
	std::list<Card>hand;
public:

	Player();
	static bool CompareCards(const Card& a, const Card& b);


	//
	void InsertCard(Card card); //mete una carta en su mano ordenada(de mayor a menor, y por palo si empatan).
	Card GetCard() const;
	Card GetCard(const Suit& suit) const;
	void SortCards();
	const std::string& GetId() const;
	const std::list<Card>& getHand() const;



};
const std::string& Player::GetId() const {
	return id;
}

const std::list<Card>& Player::getHand()const {
	return hand;
}



