#include "Board.h"

Board::Board()
{
	for (uint8_t i = 0; i < m_matrix.size(); ++i)
		m_matrix[i].fill(' ');
	for (uint8_t i = 0; i < m_matrix.size(); ++i)
		for (uint8_t j = 0; j < m_matrix[i].size(); ++j)
			m_emptyPos.push_back({ i,j });
}

void Board::UpdateBoard(const std::pair<uint16_t, uint16_t> pos, const char symbol)
{
	m_matrix[pos.first][pos.second] = symbol;
	for (uint8_t i = 0; i < m_emptyPos.size(); ++i)
		if (m_emptyPos[i] == pos)
			m_emptyPos.erase(m_emptyPos.begin() + i);
}


Board::EmptyPositions Board::GetEmptyPositions() const
{
	return m_emptyPos;
}

Board::BoardContent Board::GetMatrix() const
{
	return m_matrix;
}
