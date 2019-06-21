#include "TTG_Player.h"
#include <vector>
#include <iostream>
#include <algorithm>

TTG_Player::TTG_Player(std::string n) : Player(n)
{

}


TTG_Player::~TTG_Player()
{
}

/*Card *TTG_Player::play_a_card(Suits suit) {
	unsigned int hs = hand.size();
	if (hs == 0) {
		return nullptr;
	}

	//std::vector <Card*> myHand = get_hand();

	if (suit == NOSUIT) {
		std::random_shuffle(hand.begin(), hand.end());
		Card * card = hand[0];
		hand.erase(std::find(hand.begin(), hand.end(), card));
		return card;
	}
	else {
		Card * card = NULL;
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i]->get_suit() == suit) {
				card = hand[i];
				break;
			}

		}
		
		if (card == NULL)
		{
			std::random_shuffle(hand.begin(), hand.end());
			card = hand[0];			
		}
		
		hand.erase(std::find(hand.begin(), hand.end(), card));
		return card;
	}

}*/

