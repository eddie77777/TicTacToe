#include <iostream>
#include "GameLogic.h"
#include < stdlib.h >

int main()
{
	std::cout << "Nu e injoseala";
	/*std::cout << "For SINGLE PLAYER press [0] || For MULTI PLAYER press [1]\n";
	bool isHuman;
	std::cin >> isHuman;
	std::cout << "Who should start?\nFor PLAYER 1 press [0] || For PLAYER 2 press [1]\n";
	bool whoStarts;
	std::cin >> whoStarts;
	system("CLS");
	GameLogic gamelogic(isHuman, whoStarts);
	uint16_t whichPlayer = whoStarts;
	while (gamelogic.GetBoard().GameState() == Board::State::Playing)
	{
		system("CLS");
		if (whichPlayer % 2 == 0)
			std::cout << "Player 1 turn: \n";
		if (whichPlayer % 2 == 1)
			std::cout << "Player 2 turn: \n";
		gamelogic.ShowTable(std::cout);
		std::cout << '\n';
		if (whichPlayer % 2 == 0 || isHuman)
		{
			std::cout << "Choose a position in the board.\n";
			int i, j;
			do {
				do {
					std::cout << "i = ";
					std::cin >> i;
				} while (i > gamelogic.GetBoard().GetBoardHeight() - 1);
				do {
					std::cout << "j = ";
					std::cin >> j;
				} while (j > gamelogic.GetBoard().GetBoardWidth() - 1);
			} while (!gamelogic.GetBoard().CheckIfAddOnPos({ i,j }));
			if (whichPlayer % 2 == 0)
				gamelogic.PlayerPlacesSymbol(gamelogic.GetPlayer1());
			else
				gamelogic.PlayerPlacesSymbol(gamelogic.GetPlayer2());
			++whichPlayer;
		}
		else
		{
			gamelogic.PlayerPlacesSymbol(gamelogic.GetPlayer2());
			++whichPlayer;
		}

		if (gamelogic.GetBoard().GameState() == Board::State::Win)
		{
			system("CLS");
			gamelogic.ShowTable(std::cout);
			if(whichPlayer % 2)
				std::cout << "\n\nPLAYER 1 won!";
			else
				if(isHuman)
					std::cout << "\n\nPLAYER 2 won!";
				else
					std::cout << "\n\nCOMPUTER won!";
			return 0;
		}
		if (gamelogic.GetBoard().GameState() == Board::State::Tie)
		{
			system("CLS");
			gamelogic.ShowTable(std::cout);
			std::cout << "Tied";
			return 0;
		}

		std::cout << "\n\n";
	}*/
	//TODO: destructori, verificari pt datele introduse ( linie, coloana inexistenta sau ocupata )
}