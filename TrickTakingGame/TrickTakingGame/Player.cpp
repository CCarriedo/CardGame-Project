#include "Player.h"
#include <algorithm>


Player::Player(std::string n){
    name = n;
    points = 0;
}

Player::Player(){
    points = 0;
}


Player::~Player(){
    clear_hand();
}

void Player::clear_hand() {
    hand.clear();
}

void Player::accept_card(Card *card) {
    hand.push_back(card);
}

void Player::set_name(std::string n) {
    name = n;
}

void Player::display() {
    std::cout << "Name: " << name << " Tricks: " << tricksWon << std::endl;
	std::sort(hand.begin(), hand.end(), Card::compare);
    for(auto c : hand) {
        c->display();
    }
    std::cout << std::endl;
}

void Player::displayLess(){
	std::cout << "Name: " << name << " Tricks: " << tricksWon << std::endl;
	std::cout << std::endl;
}

std::vector<Card *> Player::get_hand() {
    return hand;
}

