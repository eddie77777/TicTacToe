#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"
#include <memory>

using Position = std::pair<int, int>;
using IStrategyPtr = std::shared_ptr<class IStrategy>;

class IStrategy {
public:
	virtual Position GetPosition(Board board) = 0;
};