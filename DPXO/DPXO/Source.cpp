#include <iostream>
#include "HPlayer.h"
#include "GameLogic.h"
#include "ConsoleListener.h"
#include <stdlib.h>
#include <string>



int main()
{
	GameLogic* game = new GameLogic();
	EGameMode gameMode;
	std::string s_mode;
	int mode;
	while (true) 
	{
		std::cout << "Choose game mode: [0] Single Player  || [1] Multi Player\n";
		std::cin >> s_mode;
		try {
			mode = std::stoi(s_mode);
			if (mode != 0 && mode != 1)
				std::cout << "Invalid game mode!\n";
			else
				break;
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Invalid game mode!\n";
		}
	}
	system("CLS");
	if (mode)
	{
		std::cout << "You chose SiNGLE PLAYER MODE.\n";
		gameMode = EGameMode::Multiplayer;
	}
	else
	{
		gameMode = EGameMode::Singleplayer;
		std::cout << "You chose MULTi PLAYER MODE.\n";
	}
	auto gameObserver1 = std::make_shared<ConsoleListener>(1, game->GetGame());
	game->GetGame()->AddListener(gameObserver1);
	gameObserver1->ShowTable(std::cout, 1);
	while (game->GetGame()->GetState() == EGameState::Playing)
	{
		game->MakeMove(gameMode);
	}
	game->GetGame()->GameOver();
	game->GetGame()->RemoveListener(gameObserver1);
	return 0;
}