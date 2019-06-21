#pragma once
#include "TTG_Player.h"
class SmartAI :
	public Player
{

	int highestValue = 0;
	int lowestValue = 15;

public:
	SmartAI(std::string n);
	~SmartAI();
	Card * play_a_card(Suits suit, Card * card2);
	void dontHaveTrumps(Card * &card);
	void haveTrumps(unsigned int hs, Suits suit, Card * &card, Card * bestCard);
	Card * FirstCard(unsigned int hs);
};

