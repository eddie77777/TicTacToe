#include "HPlayer.h"
#include <iostream>
#include <string>

bool HPlayer::PlaceSymbol(Game& game)
{
	std::pair<uint16_t, uint16_t> pos;
	std::string s_line, s_column;
	uint16_t line, column;
	std::cout << "line: ";
	while (true)
	{
		std::cin >> s_line;
		try {
			size_t maximumBoardHeight = game.GetMatHeight();
			if (s_line.size() == 1)
			{
				line = std::stoi(s_line);
				if (line < 0 || line > Board::kHeight - 1)
					std::cout << "Valoare prea mare. (input maxim: " << game.GetMatHeight() - 1 << ")";
				else
					break;
			}
			else
				std::cout << "Valoare prea mare. (input maxim: " << game.GetMatHeight() - 1 << ")";
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Argument invalid";
		}
	}

	std::cout << "column: ";
	while (true)
	{
		std::cin >> s_column;
		try {
			size_t maximumBoardWidth = game.GetMatWidth();
			if (s_column.size() == 1)
			{
				column = std::stoi(s_column);
				if (column < 0 || column > Board::kWidth - 1)
					std::cout << "Valoare prea mare. (input maxim: " << game.GetMatWidth() - 1 << ")";
				else
					break;
			}
			else
				std::cout << "Valoare prea mare. (input maxim: " << game.GetMatWidth() - 1 << ")";
		}
		catch (std::invalid_argument e)
		{
			std::cout << "Argument invalid";
		}
	}
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
