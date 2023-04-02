#pragma once
#include "IStrategy.h"

class MediumDifficultStrategy : public IStrategy 
{
private:
	Position WinOrBlock(char symbol, Board board);
	Position MiddleEdge(Board board);
	Position Corner(char symbol, Board board);
	
protected:
	Position DifficultMove(Board board);
};

