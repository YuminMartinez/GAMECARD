
#include "util.h"

Card::Card(Suit s, int v) : m_suit(s), m_value(v) {}

int Card::getValue() const {
    return m_value;
}

bool Card::operator==(const Card& other) const {
    return m_suit == other.m_suit && m_value == other.m_value; 
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const std::string suits[] = { "CLUB", "SPADE", "DIAMOND", "HEART" };
    os << "(" << suits[static_cast<int>(card.getSuit())] << "," << card.getValue() << ")"; 
    return os;
}
