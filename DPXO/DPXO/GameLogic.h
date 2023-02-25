#pragma once
#include "Board.h"
#include "CPlayer.h"
#include "HPlayer.h"

class GameLogic
{
public:
	GameLogic(bool isHuman, bool p1Starts);
	~GameLogic();
	Board GetBoard()const;
	IPlayer* GetPlayer1()const;
	IPlayer* GetPlayer2()const;

private:
	Board m_board;
	IPlayer* m_player1;
	IPlayer* m_player2;
	
private:
	const char kFirstSymbol = 'X';
	const char kSecondSymbol = '0';
	
	

};

