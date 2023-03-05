#pragma once
#include "IPlayer.h"

class HPlayer : virtual public IPlayer
{
public:
	HPlayer() = default;
	virtual bool PlaceSymbol(Board& board);
};

