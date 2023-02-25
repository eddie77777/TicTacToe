#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"

class IPlayer
{
protected:
	char symbol;
	IPlayer() = default;
public:
	virtual void ChoosePosition(std::pair<uint16_t, uint16_t> pos, const Board& board) = 0;
	void SetSymbol(char newSymbol);
};