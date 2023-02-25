#include "HPlayer.h"

bool HPlayer::PlaceSymbol(std::pair<uint16_t, uint16_t> &pos, Board& board)
{
	if (board.CheckIfAddOnPos(pos))
	{ 
		board.SetContentOnPos(pos, m_symbol);
		return 1;
	}
	else return 0;
}
