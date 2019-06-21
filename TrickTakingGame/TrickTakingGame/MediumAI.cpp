#include "MediumAI.h"
#include <vector>
#include <iostream>
#include <algorithm>


MediumAI::MediumAI(std::string n) : Player(n){
}


MediumAI::~MediumAI(){
}

Card * MediumAI::play_a_card(Suits suit, Card * card2){
	
	unsigned int hs = hand.size();
	if (hs == 0) {
		return nullptr;
	}
	
	highestValue = 0;
	lowestValue = 15;
	//std::vector <Card*> myHand = get_hand();

	if (suit == NOSUIT) {
		return FirstCard();
	}
	else {
		Card * card = NULL;
		haveTrumps(suit, card);

		dontHaveTrumps(card);

		hand.erase(std::find(hand.begin(), hand.end(), card));
		return card;
	}
}

void MediumAI::dontHaveTrumps(Card * &card){
	
	if (card == NULL){
		for (int i = 0; i < hand.size(); i++){
			if (hand[i]->get_value() < lowestValue){
				card = hand[i];
				lowestValue = hand[i]->get_value();
			}
		}
	}
}

void MediumAI::haveTrumps(Suits suit, Card * &card){
	
	for (int i = 0; i < hand.size(); i++){
		if (hand[i]->get_suit() == suit){
			card = hand[i];
			break;
		}
	}
}

Card * MediumAI::FirstCard(){
	
	Card * card;

	for (int i = 0; i < hand.size(); i++){
		if (hand[i]->get_value() > highestValue){
			card = hand[i];
			highestValue = hand[i]->get_value();
		}
	}

	hand.erase(std::find(hand.begin(), hand.end(), card));
	return card;
}
