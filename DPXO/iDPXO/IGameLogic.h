#pragma once
#include "IPlayer.h"


class IGameLogic
{
public:
	IGameLogic(bool isHuman, bool p1Starts);

public:
	virtual void PlayerPlacesSymbol(IPlayer* player) = 0; 

};
