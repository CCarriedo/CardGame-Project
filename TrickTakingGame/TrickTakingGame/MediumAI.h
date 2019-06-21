#pragma once
#include "TTG_Player.h"
class MediumAI :
	public Player
{

	int highestValue = 0;
	int lowestValue = 15;

public:
	MediumAI(std::string n);
	~MediumAI();
	Card *play_a_card(Suits suit, Card * card2);
	void dontHaveTrumps(Card * &card);
	void haveTrumps(Suits suit, Card * &card);
	Card * FirstCard();
};

