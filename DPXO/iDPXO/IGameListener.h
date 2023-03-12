#pragma once

#include <memory>

class IGameListener
{
public:
	virtual void OnMakeMove() = 0;
	virtual void OnGameOver() = 0;
};

using IGameListenerPtr = std::shared_ptr<IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<IGameListener>;
