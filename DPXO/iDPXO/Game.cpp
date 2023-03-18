#include "Game.h"

bool Game::CheckIfAddOnPos(Pos pos) const
{
	if (pos.first < 0 || pos.second < 0)
		return false;
	if (pos.first >= m_board.GetMatHeight() || pos.second >= m_board.GetMatWidth())
		return false;
	if (m_board.GetMatrix()[pos.first][pos.second] != ' ')
		return false;
	return true;
}

EMoveResult Game::MakeMove(Pos position, EGameMode gameMode)
{
	char symbol;
	if (m_moveNo % 2 == 0)
		symbol = 'X';
	else
		symbol = '0';
	if (gameMode == EGameMode::Multiplayer)
	{
		if (CheckIfAddOnPos(position))
		{
			SetContentOnPos(position, symbol);
			m_moveNo++;
			return EMoveResult::Success;
		}
		else
			return EMoveResult::Fail;
	}
	else
	{
		if (CheckIfAddOnPos(position))
		{
			SetContentOnPos(position, 'X');
			SetContentOnPos(m_board.GetARandomEmptyPos(), '0');
			return EMoveResult::Success;
			//TODO: Sa nu mai hardcodez simbolul pentru singleplayer mode
			//Sa am grija ca la ultima miscare, in functie GetARandomEmptyPos sa nu imi returneze
			//o pozitie invalida
		}
		else
			return EMoveResult::Fail;
	}
}

BoardContent Game::GetBoardContent()
{
	return m_board.GetMatrix();
}

EGameState Game::GetState()
{
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[0][1] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[0][2] && m_board.GetMatrix()[0][0] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[1][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[1][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[1][0] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[2][0] == m_board.GetMatrix()[2][1] && m_board.GetMatrix()[2][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[2][0] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[1][0] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[2][0] && m_board.GetMatrix()[0][0] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[0][1] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][1] == m_board.GetMatrix()[2][1] && m_board.GetMatrix()[0][1] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[0][2] == m_board.GetMatrix()[1][2] && m_board.GetMatrix()[0][2] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[0][2] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[0][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][0] == m_board.GetMatrix()[2][2] && m_board.GetMatrix()[0][0] != ' ')
		return EGameState::Win;
	if (m_board.GetMatrix()[0][2] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[0][2] == m_board.GetMatrix()[2][0] && m_board.GetMatrix()[0][2] != ' ')
		return EGameState::Win;
	if (m_board.GetEmptyPositions().empty())
		return EGameState::Tie;
	return EGameState::Playing;
}

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
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

uint16_t Game::GetMoveNo()
{
	return m_moveNo;
}

void Game::SetContentOnPos(Pos pos, char symbol)
{
	m_board.UpdateBoard(pos, symbol);
	for(auto obs : m_observers)
		if (auto sp = obs.lock())
		{
			sp->OnMakeMove(pos, m_moveNo % 2);
		}
}
