
#include "util.h"

Card::Card(Suit s, int v) : suit(s), value(v) {}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && value == other.value;
}