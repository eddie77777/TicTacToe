#include <iostream>
#include "GameLogic.h"
#include < stdlib.h >

int main()
{
	std::cout << "For human vs human press 1 || For human vs computer press 0\n";
	bool isHuman;
	std::cin >> isHuman;
	std::cout << "Who should start?\nFor player 1 press 1 || For player 2 press 0\n";
	bool whoStarts;
	std::cin >> whoStarts;
	system("CLS");
	GameLogic gamelogic(isHuman,whoStarts);
	uint16_t whichPlayer = whoStarts;
	while (gamelogic.GetBoard().GameState() == Board::State::Playing)
	{
		system("CLS");
		if (whichPlayer % 2 == 1)
			std::cout << "Player 1 turn: \n";
		if (whichPlayer % 2 == 0)
			std::cout << "Player 2 turn: \n";
		std::cout << gamelogic.GetBoard();
		std::cout << '\n';
		if (whichPlayer % 2 == 1 || isHuman)
		{
			std::cout << "Choose a position in the board.\n";
			std::cout << "i = ";
			int i;
			std::cin >> i;
			std::cout << "j = ";
			int j;
			std::cin >> j;
			if(whichPlayer % 2 == 1)
				gamelogic.PlayerPlacesSymbol(gamelogic.GetPlayer1(), { i,j });
			else 
				gamelogic.PlayerPlacesSymbol(gamelogic.GetPlayer2(), { i,j });

			++whichPlayer;
		}
		else
		{
			gamelogic.PlayerPlacesSymbol(gamelogic.GetPlayer2(), { 0,0 });
			++whichPlayer;
		}

		if (gamelogic.GetBoard().GameState() == Board::State::Win)
		{
			system("CLS");
			std::cout << gamelogic.GetBoard();
			if(whichPlayer % 2 == 1)
				std::cout << "\n\nPlayer1 won!";
			else 
				std::cout << "\n\nPlayer2 won!";
			return 0;
		}
		if (gamelogic.GetBoard().GameState() == Board::State::Tie)
		{
			system("CLS");
			std::cout << gamelogic.GetBoard();
			std::cout << "Tied";
			return 0;
		}

		std::cout << "\n\n";
	}
	//TODO: destructori, verificari pt datele introduse ( linie, coloana inexistenta sau ocupata )
}