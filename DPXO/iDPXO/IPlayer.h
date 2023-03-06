#pragma once
#include <cstdint>
#include <utility>
#include "Game.h"

class IPlayer
{
public:
	IPlayer() = default;
public:
	virtual bool PlaceSymbol(Game& game) = 0;
	virtual void SetSymbol(const char newSymbol) = 0;

	virtual ~IPlayer() = default;
};