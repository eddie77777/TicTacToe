#pragma once
#include "Board.h"
#include "CPlayer.h"
#include "HPlayer.h"

class GameLogic
{
private:
	const char kFirstSymbol = 'X';
	const char kSecondSymbol = '0';

public:
	GameLogic(bool isHuman, bool p1Starts);
	~GameLogic();

public:
	void PlayerPlacesSymbol(IPlayer* player); //de ce nu il pot face const pe player?

public:
	Board GetBoard()const;
	IPlayer* GetPlayer1()const;
	IPlayer* GetPlayer2()const;

private:
	Board m_board;
	IPlayer* m_player1;
	IPlayer* m_player2;
};