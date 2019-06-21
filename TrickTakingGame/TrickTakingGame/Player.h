#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Card.h"

class Player
{
protected:
    std::vector<Card *> hand;
    std::string name;
    
	unsigned int points;
	unsigned int tricksWon = 0;
	float percentage = 0;

public:
	Player();
    Player(std::string n);
    ~Player();
	virtual Card *play_a_card(Suits suit, Card * card) { return nullptr; };
    void set_name(std::string n);
	std::string get_name() { return name; }
    void accept_card(Card *card);
    void clear_hand();
    std::vector<Card *> get_hand();
    void display();
	void displayLess();

	void setPoints(int newPoints) { points = newPoints; }
	int getPoints() { return points; }

	void setTricksWon(int newTricksWon) { tricksWon = newTricksWon; }
	int getTricksWon() { return tricksWon; }

	void setPercentage(float newPercentage) { percentage = newPercentage; }
	float getPercentage() { return percentage; }
};

#endif // PLAYER_H
