#include "Board.h"

Board::Board()
{
	for (uint8_t i = 0; i < m_board.size(); i++)
		m_board[i].fill(' ');
	for (uint8_t i = 0; i < m_board.size(); i++)
		for (uint8_t j = 0; j < m_board[i].size(); j++)
			m_emptyPos.insert({ i,j });
}

bool Board::CheckIfAddOnPos(std::pair<uint16_t, uint16_t> pos)
{
	if (m_board[pos.first][pos.second] != ' ')
		return false;
	return true;
}

Board::State Board::GameState()
{
	if (m_board[0][0] == m_board[0][1] == m_board[0][2])
		return State::WIN;
	if (m_board[1][0] == m_board[1][1] == m_board[2][2])
		return State::WIN;
	if (m_board[2][0] == m_board[2][1] == m_board[2][2])
		return State::WIN;
	if (m_board[0][0] == m_board[1][0] == m_board[2][0])
		return State::WIN;
	if (m_board[0][1] == m_board[1][1] == m_board[2][1])
		return State::WIN;
	if (m_board[0][2] == m_board[1][2] == m_board[2][2])
		return State::WIN;
	if (m_board[0][0] == m_board[1][1] == m_board[2][2])
		return State::WIN;
	if (m_board[0][2] == m_board[1][1] == m_board[2][0])
		return State::WIN;
	if(m_emptyPos.empty())
		return State::TIE;
	return State::PLAYING;
}
