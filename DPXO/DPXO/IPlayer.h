#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"
#include "IPlayer.h"

class IPlayer : public IPlayer
{
protected:
	char m_symbol;
	IPlayer() = default;
public:
	virtual bool PlaceSymbol(Board& board) = 0;
	void SetSymbol(char newSymbol);
};