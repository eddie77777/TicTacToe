#include "MediumStrategy.h"
#include <random>

Position MediumStrategy::GetPosition(Board board)
{
	if (m_contor % 2)
	{
		srand(time(NULL));
		if (board.GetEmptyPositions().size() == 0)
			return { -2, -2 };
		uint16_t randomIndex = int(rand()) % board.GetEmptyPositions().size();
		return board.GetEmptyPositions()[randomIndex];
	}
	else
	{
		return DifficultMove(board);
	}
}
