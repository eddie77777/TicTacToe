#pragma once
#include "IGameListener.h"
#include "IGame.h"

class Game;

class ConsoleListener : public IGameListener
{
public:
	ConsoleListener(int no, IGame* game);

	void OnMakeMove(Pos pos, int currentPlayer) override;
	void OnGameOver(int currentPlayer, EGameState gameState) override;

private:
	int m_no;
	IGame* m_game;
};

