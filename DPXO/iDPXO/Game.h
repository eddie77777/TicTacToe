#pragma once
#include <cstdint>
#include "IGame.h"
#include "Board.h"



class Game : public IGame
{
public:
	Game(EStrategyType est);
	//Override
	EMoveResult MakeMove(Position position, EGameMode gameMode) override;
	BoardContent GetBoardContent() override;
	EGameState GetState() override;
	void GameOver() override;
	void AddListener(IGameListenerWeakPtr observer) override;
	void RemoveListener(IGameListenerWeakPtr observer) override;
	void SetStrategy(EStrategyType strategy) override;

	void CallGameOver(EGameState gameState);
	char GetSymbol();

private:
	//Methods
	bool CheckIfAddOnPos(Position pos) const;
	void SetContentOnPos(Position pos, char symbol);
private:
	Board m_board;
	uint16_t m_moveNo = 0;
	std::vector<IGameListenerWeakPtr> m_observers; 
	IStrategyPtr m_strategy;
};

