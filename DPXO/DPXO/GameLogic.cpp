#include "GameLogic.h"
#include "CPlayer.h"
#include "HPlayer.h"

GameLogic::GameLogic()
{
	m_game = IGame::Produce();
}

void GameLogic::ShowTable(std::ostream& os, uint16_t whoIsPlacing)
{
	os << "Player " << whoIsPlacing << "'s turn.\n";

	BoardContent bc = m_game->GetBoardContent();
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
