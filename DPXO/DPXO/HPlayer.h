#pragma once
#include "IPlayer.h"
#include "Game.h"

class HPlayer : public IPlayer
{
private:
	char m_symbol;
public:
	HPlayer() = default;
	virtual bool PlaceSymbol(Game& game) override;
	void SetSymbol(const char newSymbol) override;
};

