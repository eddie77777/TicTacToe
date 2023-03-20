#pragma once
#include <memory>

enum class EGameState;

using Pos = std::pair<uint16_t, uint16_t>;

class IGameListener
{
public:
	//Methods

	/// Offers to users info about game state
	/// \param pos the last position which the player made the move on
	/// \param which player made the move
	virtual void OnMakeMove(Pos pos, int currentPlayer) = 0;

	/// Offers to users info about how the game ended 
	/// \param which player made the move
	/// \param gameState the state of the game ( tie,win )
	virtual void OnGameOver(int currentPlayer, EGameState gameState) = 0;

	//Destructor
	virtual ~IGameListener() = default;
};

using IGameListenerPtr = std::shared_ptr<IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<IGameListener>;
