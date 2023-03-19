#include <iostream>
#include "HPlayer.h"
#include "GameLogic.h"
#include "ConsoleListener.h"
#include <stdlib.h>

int main()
{
	GameLogic* game = new GameLogic();
	EGameMode gameMode;
	std::cout << "Choose game mode: [0] Single Player  || [1] Multi Player\n";
	bool mode;
	std::cin >> mode;
	std::cout << '\n';
	if (mode)
	{
		gameMode = EGameMode::Multiplayer;
	}
	else
	{
		gameMode = EGameMode::Singleplayer;
	}

	auto gameObserver1 = std::make_shared<ConsoleListener>(1, game->GetGame());
	game->GetGame()->AddListener(gameObserver1);
	system("CLS");
	gameObserver1->ShowTable(std::cout, 1);
	while (game->GetGame()->GetState() == EGameState::Playing)
	{
		game->MakeMove(gameMode);
	}
	game->GetGame()->GameOver();
	return 0;
	//TODO: Sa fac afisare corecta si pentru jocul cu computer
}