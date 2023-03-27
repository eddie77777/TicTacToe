#include "EasyStrategy.h"
#include <random>

Position EasyStrategy::GetPosition(Board board)
{
	srand(time(NULL));
	if (board.GetEmptyPositions().size() == 0)
		return { -2, -2 };
	uint16_t randomIndex = int(rand()) % board.GetEmptyPositions().size();
	return board.GetEmptyPositions()[randomIndex];
}
