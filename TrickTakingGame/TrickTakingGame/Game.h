#ifndef GAME_H
#define GAME_H

#include "defs.h"
#include "Card.h"
#include "PackSingleton.h"
#include "Player.h"
#include <map>
#include <string>
using namespace std;


class Game
{
	static Game* instance;

public:
	static Game* Instance();
	static void Release();
	void play_ai_game();
	void play_human_game();

	void readGamePointsText();

	void saveToText();

	void play_a_hand();

	void CreateAIPlayers();
	void CreatePlayers();

	void handle_add(std::string n, int score, float percentage);

private:
	Game();
	~Game();
	PackSingleton *pack;
	std::vector <Player*> players;
	int mostTricks = 0;
	int trickWinner = 0;
	std::string winner;
	int highestCard = 0;
	Card * bestCard;
	int totalPoints = 0;

	map<string, int> scores;
};

#endif // GAME_H
