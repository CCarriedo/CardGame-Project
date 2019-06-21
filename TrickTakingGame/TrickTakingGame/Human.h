#pragma once
#include "Player.h"
class Human :
	public Player
{

	int hintsLeft = 3;
	int highestValue = 0;
	int lowestValue = 15;
	bool canPlayTrumps;
public:
	Human(std::string n);
	~Human();

	Card *play_a_card(Suits suit, Card * card2);
	Card * wrongSuitLoop(Card * &card, Suits suit, std::string &cardName);
	void cardNullLoop(std::string &cardName, Card * &card);
	void useHint(Suits suit, Card * card);
	void dontHaveTrumps(Card *& card);
	void haveTrumps(unsigned int hs, Suits suit, Card *& card, Card * bestCard);
	Card * FirstCard(unsigned int hs);
};

