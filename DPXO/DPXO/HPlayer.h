#pragma once
#include "IPlayer.h"

class HPlayer : virtual public IPlayer
{
	HPlayer();
	virtual void ChoosePosition(std::pair<uint16_t, uint16_t> pos, const Board& board);
};

