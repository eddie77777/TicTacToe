#include "GameLogic.h"
#include "CPlayer.h"
#include "HPlayer.h"

GameLogic::GameLogic(bool isHuman, bool p1Starts)
{
	if (isHuman)
	{
		m_player1 = new HPlayer();
		m_player2 = new HPlayer();
	}
	else
	{
		m_player1 = new HPlayer();
		m_player2 = new CPlayer();
	}

	if (p1Starts == 0)
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

void GameLogic::PlayerPlacesSymbol(IPlayer* player)
{
	player->PlaceSymbol(m_board);
}

void GameLogic::ShowTable(std::ostream& os)
{
	Board::BoardContent bc = m_board.GetBoardContent();

	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[0][0] << "  " << '|' << "  " << bc[0][1] << "  " << '|' << "  " << bc[0][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "-----" << '|' << "-----" << '|' << "-----\n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[1][0] << "  " << '|' << "  " << bc[1][1] << "  " << '|' << "  " << bc[1][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "-----" << '|' << "-----" << '|' << "-----\n";
	os << "     " << '|' << "     " << '|' << "     \n";
	os << "  " << bc[2][0] << "  " << '|' << "  " << bc[2][1] << "  " << '|' << "  " << bc[2][2] << "  \n";
	os << "     " << '|' << "     " << '|' << "     \n";
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
