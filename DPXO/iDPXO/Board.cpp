#include "Board.h"

Board::Board()
{
	for (uint8_t i = 0; i < m_board.size(); ++i)
		m_board[i].fill(' ');
	for (uint8_t i = 0; i < m_board.size(); ++i)
		for (uint8_t j = 0; j < m_board[i].size(); ++j)
			m_emptyPos.push_back({ i,j });
}

bool Board::CheckIfAddOnPos(std::pair<uint16_t, uint16_t> pos)
{
	if (m_board[pos.first][pos.second] != ' ')
		return false;
	return true;
}

Board::State Board::GameState()
{
	if (m_board[0][0] == m_board[0][1] && m_board[0][0] == m_board[0][2] && m_board[0][0] != ' ')
		return State::Win;
	if (m_board[1][0] == m_board[1][1] && m_board[1][0] == m_board[2][2] && m_board[1][0] != ' ')
		return State::Win;
	if (m_board[2][0] == m_board[2][1] && m_board[2][0] == m_board[2][2] && m_board[2][0] != ' ')
		return State::Win;
	if (m_board[0][0] == m_board[1][0] && m_board[0][0] == m_board[2][0] && m_board[0][0] != ' ')
		return State::Win;
	if (m_board[0][1] == m_board[1][1] && m_board[0][1] == m_board[2][1] && m_board[0][1] != ' ')
		return State::Win;
	if (m_board[0][2] == m_board[1][2] && m_board[0][2] == m_board[2][2] && m_board[0][2] != ' ')
		return State::Win;
	if (m_board[0][0] == m_board[1][1] && m_board[0][0] == m_board[2][2] && m_board[0][0] != ' ')
		return State::Win;
	if (m_board[0][2] == m_board[1][1] && m_board[0][2] == m_board[2][0] && m_board[0][2] != ' ')
		return State::Win;
	if (m_emptyPos.empty())
		return State::Tie;
	return State::Playing;
}

Board::BoardContent Board::GetBoardContent() const
{
	return m_board;
}

size_t Board::GetBoardWidth() const
{
	return kWidth;
}

size_t Board::GetBoardHeight() const
{
	return kHeight;
}

void Board::SetContentOnPos(std::pair<uint16_t, uint16_t> pos, char symbol)
{
	m_board[pos.first][pos.second] = symbol;
	for (uint8_t i = 0; i < m_emptyPos.size(); ++i)
		if (m_emptyPos[i] == pos)
			m_emptyPos.erase(m_emptyPos.begin() + i);
}

std::pair<uint16_t, uint16_t> Board::GetARandomEmptyPos()
{
	srand(time(NULL));
	uint16_t randomIndex = rand() % m_emptyPos.size();
	return m_emptyPos[randomIndex];
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	Board::BoardContent bc = board.GetBoardContent();

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
	return os;
}
