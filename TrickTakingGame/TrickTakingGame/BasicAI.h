#pragma once
#include "TTG_Player.h"
class BasicAI :
	public Player
{
public:
	BasicAI(std::string n);
	~BasicAI();
	Card *play_a_card(Suits suit, Card * card2);
	void dontHaveTrumps(Card * &card);
	void haveTrumps(Suits suit, Card * &card);
	Card * firstCard();
};

