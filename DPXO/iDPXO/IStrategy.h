#include <cstdint>
#include <utility>
#include "Board.h"

using Position = std::pair<uint16_t, uint16_t>;
using IStrategyPtr = std::unique_ptr<class IStrategy>;

class IStrategy {
public:
	virtual Position GetPosition(Board board) = 0;
};