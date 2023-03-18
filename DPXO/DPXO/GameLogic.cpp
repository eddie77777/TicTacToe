#include "GameLogic.h"
#include "CPlayer.h"
#include "HPlayer.h"
#include <string>

GameLogic::GameLogic()
{
	std::cout << "Let's start the game!\n";
	m_game = IGame::Produce();
}

void GameLogic::ShowTable(std::ostream& os, uint16_t whoIsPlacing)
{
	system("CLS");
	os << "Player " << whoIsPlacing % 2 + 1<< "'s turn.\n";

	BoardContent bc = m_game->GetBoardContent();
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[0][0] << "  " << '|' << "  " << bc[0][1] << "  " << '|' << "  " << bc[0][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "-----" << '|' << "-----" << '|' << "-----\n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[1][0] << "  " << '|' << "  " << bc[1][1] << "  " << '|' << "  " << bc[1][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "-----" << '|' << "-----" << '|' << "-----\n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[2][0] << "  " << '|' << "  " << bc[2][1] << "  " << '|' << "  " << bc[2][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
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

EGameState GameLogic::GetGameState()
{
	return m_game->GetState();
}
