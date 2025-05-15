#include "util.h"
Player::Player(const std::string& playerId)
{
    id = playerId;
}
bool Player::CompareCards(const Card& a, const Card& b) 
{
    if (a.getSuit() != b.getSuit()) 
    {
        // Orden descendente por valor
        return static_cast<int>(a.getSuit()) > static_cast<int>(b.getSuit());
    }
    return a.getValue() > b.getValue();
}



void Player::InsertCard(Card card) {
    auto it = hand.begin(); //  empezamos al principio de la mano

    //vamos comparando  y pasando por el 
    while (it != hand.end() && CompareCards(*it, card)) {
        ++it;
    }
    hand.insert(it, card);
}

Card Player::GetCard(const Suit& suit) const 
{
    Card mayor(Suit::CLUB, 0);
    for (const auto& card : hand) 
    {
        if (card.getSuit() == suit && card.getValue() > mayor.getValue()) {
            mayor = card;
        }
    }
    return mayor.getValue() != 0 ? mayor : Card(Suit::CLUB, 0); // valor por defecto
}

Card Player::GetCard() const 
{
    if (hand.empty()) return Card(Suit::CLUB, 0);
    auto it = hand.begin();
    std::advance(it, rand() % hand.size());
    return *it;
}

const std::string& Player::GetId() const {
    return id;
}

const std::list<Card>& Player::getHand() const {
    return hand;
}

void Player::SortCards() {
    hand.sort(CompareCards);
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player " << player.GetId() << ": ";
    for (const auto& card : player.getHand()) {
        os << "(" << static_cast<int>(card.getSuit()) << "," << card.getValue() << ") ";
    }
    return os;
}