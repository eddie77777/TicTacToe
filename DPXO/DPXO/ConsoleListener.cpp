#include "ConsoleListener.h"
#include <iostream>

ConsoleListener::ConsoleListener(int no, IGamePtr game)
	: m_no(no)
	, m_game(game)
{
}

void ConsoleListener::OnMakeMove(Pos pos, int currentPlayer)
{
	system("CLS");
	std::cout << "GameObserver" << m_no << "::OnMakeMove: ";
	std::cout << "Player: " << currentPlayer << " Pos: " << pos.first << ' ' << pos.second << '\n';
	ShowTable(std::cout, 3 - currentPlayer);
}

void ConsoleListener::OnGameOver(int currentPlayer, EGameState gameState)
{
	std::cout << "GameObserver" << m_no << "::OnGameOver: ";
	if (gameState == EGameState::Win)
		std::cout << "Player: " << currentPlayer << " won the game!\n";
	else
		std::cout << "Tie!";
}


void ConsoleListener::ShowTable(std::ostream& os, uint16_t currentPlayer)
{
	os << "Player " << currentPlayer << "'s turn.\n";

	BoardContent bc = m_game->GetBoardContent();
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[0][0] << "  " << '|' << "  " << bc[0][1] << "  " << '|' << "  " << bc[0][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "-----" << '|' << "-----" << '|' << "-----\n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[1][0] << "  " << '|' << "  " << bc[1][1] << "  " << '|' << "  " << bc[1][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "-----" << '|' << "-----" << '|' << "-----\n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[2][0] << "  " << '|' << "  " << bc[2][1] << "  " << '|' << "  " << bc[2][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
}