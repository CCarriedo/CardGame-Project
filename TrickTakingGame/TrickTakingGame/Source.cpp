
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "PackSingleton.h"
#include "Player.h"
#include "TTG_Player.h"
#include "Game.h"
#include <map>
#include <string>
using namespace std;

int main(){

	// This is just to give you an idea how to use some stuff...
   	Game *game = Game::Instance();
	
	std::string whichGame;

	std::cout << "Type AI to start AI game, Type Human to play game yourself" << std::endl;
	std::cin >> whichGame;

	if (whichGame == "AI" || whichGame == "ai") {
		game->CreateAIPlayers();

		do {
			game->play_ai_game();
		} while (true);
	}
	
	else if (whichGame == "Human" || whichGame == "human") {
		game->CreatePlayers();
		game->play_human_game();
	}
	
	
	

	system("pause");
	return 0;
}


