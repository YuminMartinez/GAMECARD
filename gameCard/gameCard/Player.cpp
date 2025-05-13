#include "util.h"
Player::Player()
{
	



}

bool Player::CompareCards(const Card& a, const Card& b) {
    if (a.getSuit() != b.getSuit()) {
        return static_cast<int>(a.getSuit()) < static_cast<int>(b.getSuit());
    }
    return a.getValue() > b.getValue(); // Orden descendente por valor
}



void Player::InsertCard(Card card) {
    auto it = hand.begin(); //  empezamos al principio de la mano

    //vamos comparando  y pasando por el 
    while (it != hand.end() && CompareCards(*it, card)) {
        ++it;
    }
    hand.insert(it, card);
}

Card Player::GetCard() const {
    int size = hand.size();
    if (size == 0) return Card(Suit::CLUB, 0); // valor por defecto

    int index = rand() % size;
    auto it = hand.begin();
    std::advance(it, index);
    return *it;
}

Card Player::GetCard(const Suit& suit) const {
    for (const auto& card : hand) {
        if (card.getSuit() == suit)
            return card;
    }
    return Card(Suit::CLUB, 0); // valor por defecto
}



void Player::SortCards() {
    hand.sort(CompareCards);
}

const std::string& Player::GetId() const {
    return id;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player " << player.GetId() << ": ";
    for (const auto& card : player.getHand()) {
        os << "(" << static_cast<int>(card.getSuit()) << "," << card.getValue() << ") ";
    }
    return os;
}