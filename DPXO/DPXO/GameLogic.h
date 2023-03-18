#pragma once
#include "Game.h"
#include <iostream>

class GameLogic
{
private:
	const char kFirstSymbol = 'X';
	const char kSecondSymbol = '0';

public:
	GameLogic();
private:
	uint16_t ReadPos(std::string axis);
public:
	void ShowTable(std::ostream& os, uint16_t whoIsPlacing);
	void MakeMove(EGameMode gameMode);
	EGameState GetGameState();

private:
	std::shared_ptr<IGame> m_game;
};
