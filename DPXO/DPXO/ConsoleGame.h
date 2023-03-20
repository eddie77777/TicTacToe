#pragma once
#include "Game.h"
#include <iostream>

class ConsoleGame
{
public:
	ConsoleGame();

	void MakeMove(EGameMode gameMode);
	IGamePtr GetGame();
private:
	uint16_t ReadPos(std::string axis);
	
private:
	IGamePtr m_game;
};