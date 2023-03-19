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
	if (gameMode == EGameMode::Multiplayer)
	{
		if (CheckIfAddOnPos(position))
		{
			SetContentOnPos(position, GetSymbol());
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
			SetContentOnPos(position, GetSymbol());
			m_moveNo++;
			if (m_board.GetARandomEmptyPos().first != -1)
				SetContentOnPos(m_board.GetARandomEmptyPos(), GetSymbol());
			m_moveNo++;
			return EMoveResult::Success;
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
	if (m_board.GetMatrix()[1][0] == m_board.GetMatrix()[1][1] && m_board.GetMatrix()[1][0] == m_board.GetMatrix()[1][2] && m_board.GetMatrix()[1][0] != ' ')
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

void Game::GameOver()
{
	if (GetState() == EGameState::Win)
	{
		CallGameOver(EGameState::Win);
	}
	else if (GetState() == EGameState::Tie)
	{
		CallGameOver(EGameState::Tie);
	}
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

void Game::CallGameOver(EGameState gameState)
{

	for (auto obs : m_observers)
		if (auto sp = obs.lock())
		{
			sp->OnGameOver((m_moveNo - 1) % 2 + 1, gameState);
		}
}

char Game::GetSymbol()
{
	char symbol;
	if (m_moveNo % 2 == 0)
		symbol = 'X';
	else
		symbol = '0';
	return symbol;
}

void Game::SetContentOnPos(Pos pos, char symbol)
{
	m_board.UpdateBoard(pos, symbol);
	for (auto obs : m_observers)
		if (auto sp = obs.lock())
		{
			sp->OnMakeMove(pos, m_moveNo % 2 + 1);
		}
}
