#pragma once
#include "MediumDifficultStrategy.h"

class DifficultStrategy : public IStrategy
{
private:
	Position WinOrBlock(char Symbol, Board board);
	Position MiddleEdge(Board board);
	Position Corner(Board board);
	Position DifficultMove(Board board);
public:
	Position GetPosition(Board board) override;
};

