#include <iostream>
#include "HPlayer.h"
#include "GameLogic.h"
#include "ConsoleListener.h"
#include <stdlib.h>

//bool PlayerMove(GameLogic& gamelogic, HPlayer player, uint16_t whoIsPlacing)
//{
//	//system("CLS");
//	gamelogic.ShowTable(std::cout, whoIsPlacing);
//	player.PlaceSymbol(gamelogic.GetGame());
//	if (gamelogic.GetGame().GameState() == IGame::GameState::Win)
//	{
//		//system("CLS");
//		gamelogic.ShowTable(std::cout, whoIsPlacing);
//		std::cout << "Player " << whoIsPlacing << " won!";
//		return 0;
//	}
//	if (gamelogic.GetGame().GameState() == BoardState::Tie)
//	{
//		//system("CLS");
//		gamelogic.ShowTable(std::cout, whoIsPlacing);
//		std::cout << "Tie!";
//		return 0;
//	}
//	return 1;
//}

int main()
{
	//GameLogic gamelogic;
	//HPlayer player1;
	//player1.SetSymbol('X');
	//HPlayer player2;
	//player2.SetSymbol('0');
	//uint16_t whoIsPlacing;

	//auto gameObserver1 = std::make_shared<ConsoleListener>(1, &gamelogic.GetGame());
	//gamelogic.GetGame().AddListener(gameObserver1);

	//while (gamelogic.GetGame().GameState() == BoardState::Playing)
	//{
	//	whoIsPlacing = 1;
	//	if (PlayerMove(gamelogic, player1, whoIsPlacing)) //Player 2 va mai muta doar daca nu s-a terminat jocul aici.
	//	{
	//		whoIsPlacing = 2;
	//		PlayerMove(gamelogic, player2, whoIsPlacing);
	//	}
	//}


	
	//TODO: destructori, verificari pt datele introduse ( linie, coloana inexistenta sau ocupata )
}