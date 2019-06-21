#include "SmartAI.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "VectorQuickSort.h"

SmartAI::SmartAI(std::string n) : Player(n){
}


SmartAI::~SmartAI(){
}

Card * SmartAI::play_a_card(Suits suit, Card * card2){
		
	unsigned int hs = hand.size();
	if (hs == 0) {
		return nullptr;
	}

	highestValue = 0;
	lowestValue = 15;
	
	if (suit == NOSUIT) {
		return FirstCard(hs);
	}
	else {
		Card * card = NULL;
		haveTrumps(hs, suit, card, card2);

		dontHaveTrumps(card);

		hand.erase(std::find(hand.begin(), hand.end(), card));
		return card;
	}
}

void SmartAI::dontHaveTrumps(Card * &card){
	
	if (card == NULL){
		for (int i = 0; i < hand.size(); i++){
			if (hand[i]->get_value() < lowestValue)	{
				card = hand[i];
				lowestValue = hand[i]->get_value();
			}
		}
	}
}

void SmartAI::haveTrumps(unsigned int hs, Suits suit, Card * &card, Card * bestCard){
	
	for (int i = 0; i < hs; i++){
		if (hand[i]->get_suit() == suit) {
			if (hand[i]->get_value() > bestCard->get_value()){
				if (hand[i]->get_value() > highestValue){
					card = hand[i];
					highestValue = hand[i]->get_value();
				}
			}
		}
	}

	if (card == NULL){
		for (int i = 0; i < hs; i++){
			if (hand[i]->get_suit() == suit) {
				if (hand[i]->get_value() < lowestValue){
					card = hand[i];
					lowestValue = hand[i]->get_value();
				}
			}
		}
	}
}

Card * SmartAI::FirstCard(unsigned int hs){
	
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
