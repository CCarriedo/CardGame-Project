#include "Card.h"
#include <iostream>

bool Card::compare(Card *c1, Card *c2) {
	return (*c1 < *c2);
}


Card::Card(Suits s, int v) {
    suit = s;
    value = v;
    char suitLetters[7]="XHCDS";
    char valueLetters[15]="023456789TJQKA";
    sLetter = suitLetters[suit];
    vLetter = valueLetters[value];
}

Card::~Card(void) {

}

bool Card::operator<(Card &other) {
	if(suit < other.suit) return true;
	else if((suit == other.suit) && (value < other.value)) return true;
	else return false;
}

bool Card::operator>(Card &other) {
	if(suit > other.suit) return true;
	else if((suit == other.suit) && (value > other.value)) return true;
	else return false;
}

bool Card::operator==(Card &other) {
    if((suit == other.suit) && (value == other.value)) return true;
    else return false;
}

Suits Card::get_suit() {
    return suit;
}

int Card::get_value() {
    return value;
}


// cardString is entered by the human player
// This function returns true if that string
//  represents this card, or false otherwise
bool Card::is_this_you(std::string cardString) {
    if(cardString.length() != 2) return false;
    if(cardString[0] != vLetter) return false;
    if(cardString[1] != sLetter) return false;
    
    return true;
}

void Card::display() {
    
    std::cout << *this;
}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
    os << card.vLetter << card.sLetter << " ";
    
    return os;
}


