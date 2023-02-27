#pragma once
#include "IPlayer.h"

class CPlayer : virtual public IPlayer
{
public:
	CPlayer()= default;
	virtual bool PlaceSymbol(Board& board); 
};

