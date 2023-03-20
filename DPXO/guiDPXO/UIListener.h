#pragma once
#include "IGame.h"
class UIListener : public IGameListener
{
public:
	UIListener(int no, IGamePtr game);
	void OnMakeMove(Pos pos, int currentPlayer, IGame* game) override;
	void OnGameOver(int currentPlayer, EGameState gameState) override;

private:
	int m_no;
	IGamePtr m_game;
};