#include "EasyStrategy.h"

Position EasyStrategy::GetPosition(Board board)
{
	return board.GetRandomPosition();
}
