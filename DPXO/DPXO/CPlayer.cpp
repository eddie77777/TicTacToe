#include "CPlayer.h"

bool CPlayer::ChoosePosition(std::pair<uint16_t, uint16_t> pos, Board& board)
{
	pos = board.GetARandomEmptyPos();
	board.SetContentOnPos(pos, m_symbol);
	return 1;
}
