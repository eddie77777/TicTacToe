#include "MediumStrategy.h"

Position MediumStrategy::GetPosition(Board board)
{
	if (m_contor % 2)
	{
		return board.GetRandomPosition();
	}
	else
	{
		return DifficultMove(board);
	}
}
