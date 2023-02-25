#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"

class IPlayer
{
protected:
	char m_symbol;
	IPlayer() = default;
public:
	virtual bool ChoosePosition(std::pair<uint16_t, uint16_t> pos, Board& board) = 0;
	void SetSymbol(char newSymbol);
};