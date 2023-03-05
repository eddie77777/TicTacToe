#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"

class IPlayer
{
public:
	IPlayer() = default;
public:
	virtual bool PlaceSymbol(Board& board) = 0;
};