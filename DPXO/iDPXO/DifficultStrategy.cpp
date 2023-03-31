#include "DifficultStrategy.h"

Position DifficultStrategy::GetPosition(Board board)
{
	return DifficultMove(board);
}
