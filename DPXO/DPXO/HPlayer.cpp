#include "HPlayer.h"
#include <iostream>
#include <string>

uint16_t ReadPos(std::string s_input, Game& game, std::string axis)
{
	uint16_t input;
	size_t max_size;
	if (axis == "line")
		max_size = game.GetMatWidth();
	else if (axis == "column")
		max_size = game.GetMatHeight();
	std::cout << axis << ": ";
	while (true)
	{
		std::getline(std::cin, s_input);
		try {
			size_t maximumBoardHeight = max_size;
			if (s_input.size() == 1)
			{
				input = std::stoi(s_input);
				if (input < 0 || input > Board::kHeight - 1)
				{
					std::cout << "Valoare prea mare. (input maxim: " << max_size - 1 << ")\n";
					std::cout << axis << ": ";
				}
				else
					break;
			}
			else
			{
				std::cout << "Valoare prea mare. (input maxim: " << max_size - 1 << ")\n";
				std::cout << axis << ": ";
			}
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Argument invalid (input has to be a number)\n";
			std::cout << axis << ": ";
		}
	}
	return input;
}

bool HPlayer::PlaceSymbol(Game& game)
{
	std::pair<uint16_t, uint16_t> pos;
	std::string s_line, s_column;
	uint16_t line = ReadPos(s_line, game, "line");
	uint16_t column = ReadPos(s_column, game, "column");
	pos.first = line;
	pos.second = column;
	if (game.CheckIfAddOnPos(pos))
	{
		game.SetContentOnPos(pos, m_symbol);
		return 1;
	}
	else return 0;
}

void HPlayer::SetSymbol(const char newSymbol)
{
	m_symbol = newSymbol;
}
