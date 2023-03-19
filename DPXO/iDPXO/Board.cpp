#include "Board.h"
#include <random>

Board::Board()
{
	for (uint8_t i = 0; i < m_matrix.size(); ++i)
		m_matrix[i].fill(' ');
	for (uint8_t i = 0; i < m_matrix.size(); ++i)
		for (uint8_t j = 0; j < m_matrix[i].size(); ++j)
			m_emptyPos.push_back({ i,j });
}

void Board::UpdateBoard(Pos pos, char symbol)
{
	m_matrix[pos.first][pos.second] = symbol;
	for (uint8_t i = 0; i < m_emptyPos.size(); ++i)
		if (m_emptyPos[i] == pos)
			m_emptyPos.erase(m_emptyPos.begin() + i);
}


Pos Board::GetARandomEmptyPos() const
{
	srand(time(NULL));
	if (m_emptyPos.size() == 0)
		return { -1, -1 };
	uint16_t randomIndex = int(rand()) % m_emptyPos.size();
	return m_emptyPos[randomIndex];
}

EmptyPositions Board::GetEmptyPositions() const
{
	return m_emptyPos;
}

BoardContent Board::GetMatrix() const
{
	return m_matrix;
}

size_t Board::GetMatWidth() const
{
	return kWidth;
}

size_t Board::GetMatHeight() const
{
	return kHeight;
}
