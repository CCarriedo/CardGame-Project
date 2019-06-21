#include "PackSingleton.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "defs.h"
#include "PseudoRandomNumberGenerator.h"

PackSingleton* PackSingleton::instance = 0;

PackSingleton::PackSingleton(){
   
	cardsDealt = 0;

   for(int s=Hearts; s <= Spades; s++) {
 		for(int v=1; v <= 13; v++) {
			Card *newCard = new Card((Suits)s, v);
			cards.push_back(newCard);
		}
	}
}

PackSingleton::~PackSingleton(){
    for(unsigned int i=0; i < cards.size(); i++) {
        delete cards[i];
    }    
}

PackSingleton* PackSingleton::Instance(){
    if (instance == 0) {
        instance = new PackSingleton();
    }
    return instance;
}

void PackSingleton::Release(){
    if (instance) {
        delete instance;
    }
    instance = 0;
}

void PackSingleton::display() {   
    for(auto c : cards) {
        std::cout << *c << std::endl;
    }
}

void PackSingleton::shuffle(int howManyTimes) {
    PseudoRandomNumberGenerator *prng = PseudoRandomNumberGenerator::Instance();

    for(auto i=0; i < howManyTimes; i++) {
        std::shuffle(cards.begin(), cards.end(), prng->get_prng());
    }
    cardsDealt = 0;
}

bool PackSingleton::deal(std::vector<Player *> players, unsigned int howManyCards) {
    unsigned int numPlayers = players.size();
    Card *card;
    
	if(howManyCards < 1) {
		howManyCards = 1;
	}
	if(howManyCards > (cards.size() / numPlayers)) {
		howManyCards = cards.size() / numPlayers;
	}
    
    for(unsigned int i=0; i < howManyCards; i++) {
        for(auto p : players) {
            cardsDealt++;
            card = cards.front();
            p->accept_card(card);
            cards.pop_front();
            cards.push_back(card);
        }
    }
    return true;
}


unsigned int PackSingleton::how_many_dealt() {
    return cardsDealt;
}




