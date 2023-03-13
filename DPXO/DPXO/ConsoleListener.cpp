#include "ConsoleListener.h"
#include <iostream>

ConsoleListener::ConsoleListener(int no, Game* game)
	: m_no(no)
	, m_game(game)
{

}

void ConsoleListener::OnMakeMove(Pos pos, int currentPlayer)
{
	std::cout << "GameObserver" << m_no << "::OnMakeMove";
}

void ConsoleListener::OnGameOver(int currentPlayer, EGameState gameState)
{
	std::cout << "GameObserver" << m_no << "::OnGameOver";
}
