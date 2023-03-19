#pragma once
#include "Game.h"
#include <iostream>

class GameLogic
{
public:
	GameLogic();

	void MakeMove(EGameMode gameMode);
	IGamePtr GetGame();
private:
	uint16_t ReadPos(std::string axis);
	
private:
	IGamePtr m_game;
};
