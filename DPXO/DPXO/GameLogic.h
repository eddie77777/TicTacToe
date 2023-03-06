#pragma once
#include "IGame.h"
#include "Board.h"

class GameLogic : public IGame
{
private:
	const char kFirstSymbol = 'X';
	const char kSecondSymbol = '0';

public:
	GameLogic(bool isHuman, bool p1Starts);
	~GameLogic();

public:
	void PlayerPlacesSymbol(IPlayer* player); //de ce nu il pot face const pe player?
	void ShowTable(std::ostream& os);

public:
	Board GetBoard() const;
	IPlayer* GetPlayer1() const;
	IPlayer* GetPlayer2() const;

private:
	Board m_board;
	IPlayer* m_player1;
	IPlayer* m_player2;
};