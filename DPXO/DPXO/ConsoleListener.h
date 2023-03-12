#pragma once
#include "IGameListener.h"

class Game;

class ConsoleListener : public IGameListener
{
public:
	ConsoleListener(int no, Game* game);

	void OnMakeMove() override;
	void OnGameOver() override;
private:
	int m_no;
	Game* m_game;
};

