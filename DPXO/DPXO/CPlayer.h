#pragma once
#include "IPlayer.h"

class CPlayer : virtual public IPlayer
{
	CPlayer();
	virtual void ChoosePosition(std::pair<uint16_t, uint16_t> pos, const Board& board);
};

