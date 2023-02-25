#include "GameLogic.h"

GameLogic::GameLogic(bool isHuman, bool p1Starts)
{
	if (isHuman)
	{
		m_player1 = new HPlayer;
		m_player2 = new HPlayer;
	}
	else
	{
		m_player1 = new HPlayer;
		m_player2 = new CPlayer;
	}

	if (p1Starts)
	{
		m_player1->SetSymbol(kFirstSymbol);
		m_player2->SetSymbol(kSecondSymbol);
	}
	else
	{
		m_player2->SetSymbol(kFirstSymbol);
		m_player1->SetSymbol(kSecondSymbol);
	}

}

GameLogic::~GameLogic()
{
	/*delete m_player1;
	delete m_player2;*/  //dc????????
}

void GameLogic::PlayerPlacesSymbol(IPlayer* player, std::pair<uint16_t,uint16_t> pos)
{
	player->PlaceSymbol(pos, m_board);
}

IPlayer* GameLogic::GetPlayer2() const
{
	return m_player2;
}

IPlayer* GameLogic::GetPlayer1() const 
{
	return m_player1;
}

Board GameLogic::GetBoard() const 
{
	return m_board;
}
