#include "Game.h"
#include <random>


bool Game::CheckIfAddOnPos(const std::pair<uint16_t, uint16_t> pos) const
{
	if (pos.first == -1 || pos.second == -1)
		return false;
	if (m_board.GetMatrix()[pos.first][pos.second] != ' ')
		return false;
	return true;
}

BoardState Game::GameState() const 
{
	uint16_t state = 0;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[0][1] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[0][2] && m_board.GetMatrix()[0][0] != ' ')
		state = 1;
	if (m_board.GetMatrix()[1][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[1][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[1][0] != ' ')
		state = 1;
	if (m_board.GetMatrix()[2][0] == m_board.GetMatrix()[2][1] && m_board.GetMatrix()[2][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[2][0] != ' ')
		state = 1;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[1][0] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[2][0] && m_board.GetMatrix()[0][0] != ' ')
		state = 1;
	if (m_board.GetMatrix()[0][1] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][1] == m_board.GetMatrix()[2][1] && m_board.GetMatrix()[0][1] != ' ')
		state = 1;
	if (m_board.GetMatrix()[0][2] == m_board.GetMatrix()[1][2] && m_board.GetMatrix()[0][2] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[0][2] != ' ')
		state = 1;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[0][0] != ' ')
		state = 1;
	if (m_board.GetMatrix()[0][2] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][2] == m_board.GetMatrix()[2][0] && m_board.GetMatrix()[0][2] != ' ')
		state = 1;
	if (m_board.GetEmptyPositions().empty())
		state = 2;
	if (state != 0)
	{
		for (auto obs : m_observers)
			if (auto sp = obs.lock())
			{
				sp->OnGameOver();
			}
		if (state == 1)
			return BoardState::Win;
		else
			return BoardState::Tie;
	}
	return BoardState::Playing;
}

void Game::AddListener(IGameListenerPtr observer)
{
	m_observers.push_back(observer);
}

void Game::RemoveListener(IGameListener* observer)
{
	for (auto it = m_observers.begin(); it != m_observers.end(); )
	{
		if (auto sp = it->lock())
		{
			if (sp.get() == observer)
				it = m_observers.erase(it);
			else
				it++;
		}
		else
			it = m_observers.erase(it);
	}
}

Board::BoardContent Game::GetBoard() const
{
	return m_board.GetMatrix();
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
	for(auto obs : m_observers)
		if (auto sp = obs.lock())
		{
			sp->OnMakeMove();
		}
}

std::pair<uint16_t, uint16_t> Game::GetARandomEmptyPos() const
{
	srand(time(NULL));
	uint16_t randomIndex = rand() % m_board.GetEmptyPositions().size();
	return m_board.GetEmptyPositions()[randomIndex];
}
