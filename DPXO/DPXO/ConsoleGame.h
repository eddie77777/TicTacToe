#pragma once
#include "IGame.h"
#include <iostream>

class ConsoleGame
{
public:
	ConsoleGame(EStrategyType strategyType = EStrategyType::Easy);

	void MakeMove(EGameMode gameMode);
	IGamePtr GetGame();
	void SetStrategy(EStrategyType strategyType);

private:
	uint16_t ReadPos(std::string axis);
	
private:
	IGamePtr m_game;
};
