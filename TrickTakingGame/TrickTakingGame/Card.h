#pragma once
#include <ostream>
#include "defs.h"

class Card
{
private:
	int value;
	Suits suit;
    char sLetter;
    char vLetter;
public:
	Card(Suits s, int v);
	~Card(void);
	static bool compare(Card *c1, Card *c2);
    bool operator <(Card &other);
    bool operator ==(Card &other);
    bool operator >(Card &other);
	void display();
    Suits get_suit();
    int get_value();
    bool is_this_you(std::string cardString);
	friend std::ostream &operator<<(std::ostream &os, const Card &card);
};

