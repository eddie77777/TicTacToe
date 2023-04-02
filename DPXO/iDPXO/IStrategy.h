#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"
#include <memory>

using Position = std::pair<int, int>;
using IStrategyPtr = std::shared_ptr<class IStrategy>;

class IStrategy {
public:
	/// \brief Choose the position where computer place symbol, it depends on the strategy type that user have chosen
	/// \param board the board where the game is having place
	/// \returns position a position where the move must be made
	virtual Position GetPosition(Board board) = 0;

	//Destructor
	virtual ~IStrategy() = default;
};
