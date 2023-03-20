#include "ConsoleListener.h"
#include <iostream>

ConsoleListener::ConsoleListener(int no)
	: m_no(no)
{
}

void ConsoleListener::OnMakeMove(Pos pos, int currentPlayer, IGame* game)
{
	system("CLS");
	std::cout << "Last move: ";
	std::cout << "Player: " << currentPlayer << "// Pos: " 
	<< '[' << pos.first + 1 << " , " << pos.second + 1 << ']' << "\n\n";
	ShowTable(std::cout, 3 - currentPlayer, game);
}

void ConsoleListener::OnGameOver(int currentPlayer, EGameState gameState)
{
	std::cout << "GAME OVER!!! ";
	if (gameState == EGameState::Win)
		std::cout << "Player: " << currentPlayer << " won the game!\n";
	else
		std::cout << "Tie!";
}


void ConsoleListener::ShowTable(std::ostream& os, uint16_t currentPlayer, IGame* game)
{
	os << "Player " << currentPlayer << "'s turn.\n";

	BoardContent bc = game->GetBoardContent();
	os << "  |  1" << "  |  2" << "  |  3\n";
	os << "--|-----|-----|-----\n";
	os << "  |     " << '|' << "     " << '|' << "     \n";
	os << "1 |" << "  " << bc[0][0] << "  " << '|' << "  " << bc[0][1] << "  " << '|' << "  " << bc[0][2] << "  \n";
	os << "  |     " << '|' << "     " << '|' << "     \n";
	os << "--|-----" << '|' << "-----" << '|' << "-----\n";
	os << "  |     " << '|' << "     " << '|' << "     \n";
	os << "2 |" << "  " << bc[1][0] << "  " << '|' << "  " << bc[1][1] << "  " << '|' << "  " << bc[1][2] << "  \n";
	os << "  |     " << '|' << "     " << '|' << "     \n";
	os << "--|-----" << '|' << "-----" << '|' << "-----\n";
	os << "  |     " << '|' << "     " << '|' << "     \n";
	os << "3 |" << "  " << bc[2][0] << "  " << '|' << "  " << bc[2][1] << "  " << '|' << "  " << bc[2][2] << "  \n";
	os << "  |     " << '|' << "     " << '|' << "     \n";
}