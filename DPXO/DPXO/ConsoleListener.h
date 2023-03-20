#pragma once
#include "IGame.h"


class ConsoleListener : public IGameListener
{
public:
	ConsoleListener(int no);
	void OnMakeMove(Pos pos, int currentPlayer, IGame* game) override;
	void OnGameOver(int currentPlayer, EGameState gameState) override;
	void ShowTable(std::ostream& os, uint16_t currentPlayer, IGame* game);

private:
	int m_no;
};

