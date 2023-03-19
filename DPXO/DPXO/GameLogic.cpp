#include "GameLogic.h"
#include "CPlayer.h"
#include "HPlayer.h"
#include <string>

GameLogic::GameLogic()
{
	std::cout << "Let's start the game!\n";
	m_game = IGame::Produce();
}

uint16_t GameLogic::ReadPos(std::string axis)
{
	uint16_t input;
	std::string s_input;
	char c = '\0';
	std::cout << axis << ": ";
	while (true)
	{
		std::cin >> s_input;
		//std::getline(std::cin, s_input);
		try 
		{
			input = std::stoi(s_input);
			break;
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Argument invalid (input has to be a number)\n";
			std::cout << axis << ": ";
		}
	}
	return input;
}

void GameLogic::MakeMove(EGameMode gameMode)
{
	uint16_t line = ReadPos("line");
	uint16_t column = ReadPos("column");
	while (m_game->MakeMove({ line , column }, gameMode) == EMoveResult::Fail)
	{
		std::cout << "Position already filled\n";
		line = ReadPos("line");
		column = ReadPos("column");
	}
	m_game->MakeMove({ line, column }, gameMode);
}

IGamePtr GameLogic::GetGame()
{
	return m_game;
}
