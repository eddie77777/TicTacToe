#pragma once
#include "IStrategy.h"

class MediumDifficultStrategy : IStrategy 
{
private:
	Position WinOrBlock(char Symbol, Board board);
	Position MiddleEdge(Board board);
	Position Corner(Board board);
protected:
	Position DifficultMove(Board board);

};

