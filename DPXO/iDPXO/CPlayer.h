#pragma once
#include "IPlayer.h"

class CPlayer : public IPlayer
{
private:
	char m_symbol;
public:
	CPlayer() = default;
	virtual bool PlaceSymbol(Board& board);
	void SetSymbol(const char newSymbol);
	//TODO: adauga m_symbol si pt HPlayer si fa-i functia de set symbol, pt ca la noi este in interfata :)
};

