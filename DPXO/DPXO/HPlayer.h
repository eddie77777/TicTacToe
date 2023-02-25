#pragma once
#include "IPlayer.h"

class HPlayer : virtual public IPlayer
{
public:
	HPlayer() = default;
	virtual bool PlaceSymbol(std::pair<uint16_t, uint16_t> &pos, Board& board);
};

