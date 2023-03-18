#pragma once
#include <cstdint>
#include "IGame.h"
#include "Board.h"
#include "IGameListener.h"

class Game : public IGame
{
public:
	//Override
	EMoveResult MakeMove(Pos position, EGameMode gameMode) override;
	BoardContent GetBoardContent() override;
	virtual EGameState GetState() override;

private:
	//Methods
	bool CheckIfAddOnPos(Pos pos) const ;
	void SetContentOnPos(Pos pos, char symbol);

	//Listeners
	void AddListener(IGameListenerPtr observer);
	void RemoveListener(IGameListener* observer);

	//Getters
	uint16_t GetMoveNo();

private:
	Board m_board;
	uint16_t m_moveNo = 0;
	std::vector<IGameListenerWeakPtr> m_observers;
};

