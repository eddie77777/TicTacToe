#include "Board.h"

const size_t kCellWidth = 3;

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
		return State::Win;
	if (m_board[1][0] == m_board[1][1] == m_board[2][2])
		return State::Win;
	if (m_board[2][0] == m_board[2][1] == m_board[2][2])
		return State::Win;
	if (m_board[0][0] == m_board[1][0] == m_board[2][0])
		return State::Win;
	if (m_board[0][1] == m_board[1][1] == m_board[2][1])
		return State::Win;
	if (m_board[0][2] == m_board[1][2] == m_board[2][2])
		return State::Win;
	if (m_board[0][0] == m_board[1][1] == m_board[2][2])
		return State::Win;
	if (m_board[0][2] == m_board[1][1] == m_board[2][0])
		return State::Win;
	if(m_emptyPos.empty())
		return State::Tie;
	return State::Playing;
}

Board::BoardContent Board::GetBoardContent() const
{
	return m_board;
}

void Board::SetContentOnPos(std::pair<uint16_t, uint16_t> pos, char symbol)
{
	m_board[pos.first][pos.second] = symbol;
	m_emptyPos.erase({ pos.first, pos.second });
}

std::pair<uint16_t, uint16_t> Board::GetARandomEmptyPos()
{
	uint16_t randomLine = UINT16_MAX;
	uint16_t randomColumn = UINT16_MAX;
	srand(time(NULL));
	while (m_emptyPos.find({ randomLine, randomColumn }) == m_emptyPos.end()) {
		randomLine = rand() % kHeight;
		randomColumn = rand() % kWidth;
	}
	return { randomLine, randomColumn };
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	/*for (int i = 0; i < board.kHeight * kCellWidth + board.kHeight - 1; i++)
		for (int j = 0; j < board.kWidth * kCellWidth + board.kWidth - 1; j++)*/
	Board::BoardContent bc = board.GetBoardContent();

	os << "     "                  << '|' << "     "                  << '|' << "     \n";
	os << "  " << bc[0][0] << "  " << '|' << "  " << bc[0][1] << "  " << '|' << "  " << bc[0][2] << "  \n";
	os << "     "                  << '|' << "     "                  << '|' << "     \n";
	os << "-----"                  << '|' << "-----"                  << '|' << "-----\n";
	os << "     "                  << '|' << "     "                  << '|' << "     \n";
	os << "  " << bc[1][0] << "  " << '|' << "  " << bc[1][1] << "  " << '|' << "  " << bc[1][2] << "  \n";
	os << "     "                  << '|' << "     "                  << '|' << "     \n";
	os << "-----"                  << '|' << "-----"                  << '|' << "-----\n";
	os << "     "                  << '|' << "     "                  << '|' << "     \n";
	os << "  " << bc[2][0] << "  " << '|' << "  " << bc[2][1] << "  " << '|' << "  " << bc[2][2] << "  \n";
	os << "     "                  << '|' << "     "                  << '|' << "     \n";
	return os;
}
