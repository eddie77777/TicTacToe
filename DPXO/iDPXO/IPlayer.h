#pragma once
#include <cstdint>
#include <utility>
#include "IBoard.h"

class IPlayer
{
public:
	IPlayer() = default;
public:
	virtual bool PlaceSymbol(IBoard& board) = 0;
};