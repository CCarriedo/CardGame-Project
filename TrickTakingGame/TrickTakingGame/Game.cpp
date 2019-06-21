#include "Game.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include "PackSingleton.h"
#include "BasicAI.h"
#include "MediumAI.h"
#include "SmartAI.h"
#include "Human.h"
#include <fstream>



Game* Game::instance = 0;

Game::Game(){
    pack = PackSingleton::Instance();
}

Game::~Game(){
}

Game* Game::Instance(){
    if (instance == 0) {
        instance = new Game();
    }
    return instance;
}

void Game::Release(){
    if (instance) {
        delete instance;
    }
    instance = 0;
}

void Game::play_ai_game() {

	mostTricks = 0;
	trickWinner = 0;
	winner = "";
	highestCard = 0;
	bestCard = NULL;
	totalPoints = 0;
	
	readGamePointsText();

	std::random_shuffle(players.begin(), players.end());

	PackSingleton * pack = PackSingleton::Instance();
	
	pack->shuffle();
	pack->deal(players, 13);

	for (auto p : players) {
		p->display();
	}
	
	for (int i = 0; i < 4; i++)	{
		players[i]->setTricksWon(0);
	}

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 13; i++) {
		std::cout << "Cards played: ";
		play_a_hand();
		std::rotate(players.begin(), players.begin() + (trickWinner - 1), players.end());
		std::cout << "\n\n" << std::endl;
		for (auto p : players) {
			p->display();
		}
	}

	std::cout << std::endl << std::endl;
	
	for (int i = 0; i < 4; i++){
		
		if (players[i]->getTricksWon() == mostTricks){
			winner = "Tie!";
		}

		if (players[i]->getTricksWon() > mostTricks){
			mostTricks = players[i]->getTricksWon();
			winner = players[i]->get_name();
		}
	}

	if (winner == "Tie!") {
		std::cout << "There is a tie for winner of the game!";
		for (int i = 0; i < 4; i++)	{
			if(players[i]->getTricksWon() == mostTricks){
				scores[players[i]->get_name()] += 1;
				players[i]->setPoints(players[i]->getPoints() + 1);
			}
		}
	} else {
		std::cout << "Winner of the game is " << winner << "!";
		scores[winner] += 3;
	}

	std::cout << std::endl << std::endl;
	totalPoints = 0;
	for (int i = 0; i < 4; i++) {
		totalPoints = totalPoints + scores[players[i]->get_name()];
	}
	
	for (int i = 0; i < 4; i++) {
		float newPercentage = ((float)scores[players[i]->get_name()] / (float)totalPoints) * 100;
		
		if (totalPoints > 0){
			players[i]->setPercentage(newPercentage);
		}
	}
	
	saveToText();
	
	// 7. Sort the player list
	// 8. Print it out as a league table
}

void Game::play_human_game()
{
	std::random_shuffle(players.begin(), players.end());

	PackSingleton * pack = PackSingleton::Instance();

	pack->shuffle();
	pack->deal(players, 13);

	for (int i = 0; i < 4; i++) {
		if (players[i]->get_name() == "You"){
			players[i]->display();
		}
		else {
			players[i]->displayLess();
		}
	}
	

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 13; i++) {
		
		std::cout << "Cards played: ";
		play_a_hand();
		std::cout << "\n" << std::endl;
		std::rotate(players.begin(), players.begin() + (trickWinner - 1), players.end());
				
		for (int i = 0; i < 4; i++) {
			if (players[i]->get_name() == "You"){
				players[i]->display();
			}
			else {
				players[i]->displayLess();
			}
		}
		std::cout << std::endl << std::endl;
	}

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 4; i++)	{

		if (players[i]->getTricksWon() == mostTricks){
			winner = "Tie!";
		}

		if (players[i]->getTricksWon() > mostTricks){
			mostTricks = players[i]->getTricksWon();
			winner = players[i]->get_name();
		}
	}

	if (winner == "Tie!") {
		std::cout << "There is a tie for winner of the game!";
	}
	else {
		std::cout << "Winner of the game is " << winner << "!";
	}

	std::cout << std::endl << std::endl;

}

void Game::readGamePointsText()
{
	std::fstream gamePoints;
	gamePoints.open("PointsTable.txt", std::fstream::in);
	std::string key;
	int value;
	float value2;

	while (!gamePoints.eof()) {
		gamePoints >> key;
		gamePoints >> value;
		gamePoints >> value2;
		if (!gamePoints.eof()) {
			handle_add(key, value, value2);
		}
	}
	gamePoints.close();
}

void Game::saveToText()
{
	std::fstream gamePoints;
	gamePoints.open("PointsTable.txt", std::fstream::out);
	for (int i = 0; i < 4; i++){
		gamePoints << players[i]->get_name() << " " << scores[players[i]->get_name()] << " " << players[i]->getPercentage() << std::endl;
	}	
	gamePoints.close();
}

void Game::play_a_hand()
{
	Suits currentTrump = NOSUIT;
	

	for (int i = 0; i < players.size(); i++){
		
		Card *c = players[i]->play_a_card(currentTrump, bestCard);

		if (c == nullptr) {
			// This means either this player has no cards, OR...
			//  You haven't programmed the player to play the game yet!
		}
		else {
			// If this player knows how to play AND it has some cards left,
			//  it will play a card and pass it back as c. This just displays c
			c->display();
			if (i == 0) {
				currentTrump = c->get_suit();
			}
		}

		if (i == 0)	{
			bestCard = c;
			highestCard = c->get_value();
			trickWinner = i + 1;
		}
		else {
			if (c->get_suit() == currentTrump && highestCard < c->get_value())	{
				bestCard = c;
				highestCard = c->get_value();
				trickWinner = i + 1;
			}
		}	
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The winner of the trick is Player " << trickWinner;

	switch (trickWinner) {
	case 1: 
		players[0]->setTricksWon(players[0]->getTricksWon() + 1);
		break;
	case 2:
		players[1]->setTricksWon(players[1]->getTricksWon() + 1);
		break;

	case 3: 
		players[2]->setTricksWon(players[2]->getTricksWon() + 1);
		break;

	case 4:
		players[3]->setTricksWon(players[3]->getTricksWon() + 1);
		break;

	default:
		break;
	}
		
}

void Game::CreateAIPlayers(){

	BasicAI * stupidAI = new BasicAI("Biff");
	players.push_back(stupidAI);
	scores["Biff"] = 0;

	BasicAI * stupidAI2 = new BasicAI("Polly");
	players.push_back(stupidAI2);
	scores["Polly"] = 0;

	SmartAI * smartestAI = new SmartAI("Oscar");
	players.push_back(smartestAI);
	scores["Oscar"] = 0;

	MediumAI * averageAI = new MediumAI("Elle");
	players.push_back(averageAI);
	scores["Elle"] = 0;
}

void Game::CreatePlayers(){

	BasicAI * stupidAI = new BasicAI("Biff");
	players.push_back(stupidAI);
	

	BasicAI * stupidAI2 = new BasicAI("Polly");
	players.push_back(stupidAI2);
	

	Human * humanPlayer = new Human("You");
	players.push_back(humanPlayer);
	
	SmartAI * smartestAI = new SmartAI("Oscar");
	players.push_back(smartestAI);	
}

void Game::handle_add(std::string n, int score, float percentage) {
	
	scores[n] = score;
}
