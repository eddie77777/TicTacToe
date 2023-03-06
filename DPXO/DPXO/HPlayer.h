#pragma once
#include "IPlayer.h"

class HPlayer : public IPlayer
{
private:
	char m_symbol;
public:
	HPlayer() = default;
	virtual bool PlaceSymbol(Board& board);
	void SetSymbol(const char newSymbol);
};

