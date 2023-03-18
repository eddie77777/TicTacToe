#pragma once

#include <memory>
#include "IGame.h"

class IGameListener
{
public:
	virtual void OnMakeMove(Pos pos, int currentPlayer) = 0;
	virtual void OnGameOver(int currentPlayer, EGameState gameState) = 0;
};

using IGameListenerPtr = std::shared_ptr<IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<IGameListener>;
