#include "CPlayer.h"

bool CPlayer::PlaceSymbol(std::pair<uint16_t, uint16_t> &pos, Board& board)
{
	//functie de adaugare pozitie random neocupata
	pos = board.GetARandomEmptyPos();
	board.SetContentOnPos(pos,m_symbol);
	return 1;
}
