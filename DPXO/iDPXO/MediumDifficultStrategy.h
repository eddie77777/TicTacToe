#pragma once
#include "IStrategy.h"

class MediumDifficultStrategy : public IStrategy 
{
private:
	Position WinOrBlock(ECellState cellState, Board board);
	Position MiddleEdge(Board board);
	Position Corner(ECellState cellState, Board board);
	
protected:
	Position DifficultMove(Board board);
};

