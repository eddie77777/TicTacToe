#include "Game.h"
#include <random>


bool Game::CheckIfAddOnPos(const std::pair<uint16_t, uint16_t> pos) const
{

	if (m_board.GetMatrix()[pos.first][pos.second] != ' ')
		return false;
	return true;
}

BoardState Game::GameState() const 
{
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[0][1] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[0][2] && m_board.GetMatrix()[0][0] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[1][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[1][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[1][0] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[2][0] == m_board.GetMatrix()[2][1] && m_board.GetMatrix()[2][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[2][0] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[1][0] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[2][0] && m_board.GetMatrix()[0][0] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[0][1] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][1] == m_board.GetMatrix()[2][1] && m_board.GetMatrix()[0][1] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[0][2] == m_board.GetMatrix()[1][2] && m_board.GetMatrix()[0][2] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[0][2] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[0][0] != ' ')
		return BoardState::Win;
	if (m_board.GetMatrix()[0][2] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][2] == m_board.GetMatrix()[2][0] && m_board.GetMatrix()[0][2] != ' ')
		return BoardState::Win;
	if (m_board.GetEmptyPositions().empty())
		return BoardState::Tie;
	return BoardState::Playing;
}

Board Game::GetBoard() const
{
	return m_board;
}

size_t Game::GetMatWidth()
{
	return kWidth;
}

size_t Game::GetMatHeight()
{
	return kHeight;
}

void Game::SetContentOnPos(const std::pair<uint16_t, uint16_t> pos, const char symbol)
{
	m_board.UpdateBoard(pos, symbol);
}

std::pair<uint16_t, uint16_t> Game::GetARandomEmptyPos() const
{
	srand(time(NULL));
	uint16_t randomIndex = rand() % m_board.GetEmptyPositions().size();
	return m_board.GetEmptyPositions()[randomIndex];
}
