#include "BasicAI.h"
#include <vector>
#include <iostream>
#include <algorithm>


BasicAI::BasicAI(std::string n) : Player(n){
}


BasicAI::~BasicAI(){
}

Card * BasicAI::play_a_card(Suits suit, Card * card2){
	// Random

	unsigned int hs = hand.size();
	if (hs == 0) {
		return nullptr;
	}

	//std::vector <Card*> myHand = get_hand();

	if (suit == NOSUIT){
		return firstCard();
	}
	else {
		Card * card = NULL;
		haveTrumps(suit, card);

		dontHaveTrumps(card);

		hand.erase(std::find(hand.begin(), hand.end(), card));
		return card;
	}
}

void BasicAI::dontHaveTrumps(Card * &card){
	
	if (card == NULL){
		std::random_shuffle(hand.begin(), hand.end());
		card = hand[0];
	}
}

void BasicAI::haveTrumps(Suits suit, Card * &card){
	
	for (int i = 0; i < hand.size(); i++){
		if (hand[i]->get_suit() == suit) {
			card = hand[i];
			break;
		}
	}
}

Card * BasicAI::firstCard(){
	std::random_shuffle(hand.begin(), hand.end());
	Card * card = hand[0];
	hand.erase(std::find(hand.begin(), hand.end(), card));
	return card;
}
