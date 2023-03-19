#pragma once
#include <memory>

enum class EGameState {
	Playing,
	Win,
	Tie
};

using Pos = std::pair<uint16_t, uint16_t>;

class IGameListener
{
public:
	virtual void OnMakeMove(Pos pos, int currentPlayer) = 0;
	virtual void OnGameOver(int currentPlayer, EGameState gameState) = 0;

	virtual ~IGameListener() = default;
};

using IGameListenerPtr = std::shared_ptr<IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<IGameListener>;
