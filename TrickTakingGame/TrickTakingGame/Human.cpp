#include "Human.h"
#include "SmartAI.h"



Human::Human(std::string n) : Player(n)
{
}


Human::~Human()
{
}

Card * Human::play_a_card(Suits suit, Card * card2)
{
	Card * card = NULL;
	std::string cardName;
	highestValue = 0;
	lowestValue = 15;
	canPlayTrumps = false;

	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->get_suit() == suit)
		{
			canPlayTrumps = true;
		}
	}

	std::cout << std::endl;
	std::cout << "Enter the card you wish to play from your hand. So if you wanted to play the 2 of Hearts, you would enter 2H" << std::endl;
	std::cout << "For a hint on which card to play, enter the word 'hint'" << std::endl;
	std::cout << "You have " << hintsLeft << " hints left" << std::endl;
	std::cin >> cardName;

	if (cardName == "hint")
	{
		if (hintsLeft > 0) {
			useHint(suit, card2);
		}
		else {
			std::cout << "You don't have any hints left." << std::endl;
		}

		std::cout << "Enter the card you wish to play from your hand. So if you wanted to play the 2 of Hearts, you would enter 2H" << std::endl;
		std::cin >> cardName;
	}
	
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->is_this_you(cardName))
		{
			card = hand[i];
		}
	}

	if (card == NULL)
	{
		cardNullLoop(cardName, card);
	}

	
	
	if (canPlayTrumps == true) {
		do {
			if (card->get_suit() != suit)
			{
				card = wrongSuitLoop(card, suit, cardName);
			}
		} while (card->get_suit() != suit);
	}
	
	hand.erase(std::find(hand.begin(), hand.end(), card));
	return card;
}

Card * Human::wrongSuitLoop(Card * &card, Suits suit, std::string &cardName)
{
	for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i]->get_suit() == suit)
			{
				std::cout << "Please enter a legal card. If you have a card of trumps, you cannot play a card of a different suit. Please try again" << std::endl;
				std::cin >> cardName;

				for (int i = 0; i < hand.size(); i++)
				{
					if (hand[i]->is_this_you(cardName))
					{
						card = hand[i];							
					}
				}
				
				break;
			}
			
		}
	
	return card;
}

void Human::cardNullLoop(std::string &cardName, Card * &card)
{
	do {

		std::cout << "You don't seem to have that card. Please try again with a card in your hand" << std::endl;
		std::cin >> cardName;

		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i]->is_this_you(cardName))
			{
				card = hand[i];
			}
		}

	} while (card == NULL);
}

void Human::useHint(Suits suit, Card * card)
{
	Card * hintCard;
	highestValue = 0;
	lowestValue = 15;

	if (suit == NOSUIT) {
		hintCard = FirstCard(hand.size());
	}
	else {
		Card * differentCard = NULL;
		haveTrumps(hand.size(), suit, differentCard, card);

		dontHaveTrumps(differentCard);

		hintCard = differentCard;
	}
	
	hintsLeft--;
	std::cout << "The card the smart AI would play in this scenario is ";
	hintCard->display();
	std::cout << std::endl;
}

void Human::dontHaveTrumps(Card * &card)
{
	if (card == NULL)
	{
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i]->get_value() < lowestValue)
			{
				card = hand[i];
				lowestValue = hand[i]->get_value();
			}

		}
	}

}

void Human::haveTrumps(unsigned int hs, Suits suit, Card * &card, Card * bestCard)
{
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

Card * Human::FirstCard(unsigned int hs){
	
	Card * differentCard;

	for (int i = 0; i < hand.size(); i++){
		if (hand[i]->get_value() > highestValue){
			differentCard = hand[i];
			highestValue = hand[i]->get_value();
		}
	}
	return differentCard;
}
