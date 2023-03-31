#include "StrategyFunctions.h"

Position WinOrBlock(char symbol, Board board)
{
	//checks for every row if the last two positions are the same
	for (uint16_t i = 0; i < 3; i++)
	{
		if (board.GetMatrix()[i][1] == board.GetMatrix()[i][2] && board.GetMatrix()[i][1] == symbol)
			return { i,0 };
	}
	
	//checks for every column if the last two positions are the same
	for (uint16_t j = 0; j < 3; j++)
	{
		if (board.GetMatrix()[1][j] == board.GetMatrix()[2][j] && board.GetMatrix()[1][j] == symbol)
			return { 0,j };
	}

	//checks for every row if the first and the last positions are the same
	for (uint16_t i = 0; i < 3; i++)
	{
		if(board.GetMatrix()[i][0] == board.GetMatrix()[i][2] && board.GetMatrix()[i][0] == symbol)
			return { i,1 };
	}

	//checks for every column if the first and the last positions are the same
	for (uint16_t j = 0; j < 3; j++)
	{
		if (board.GetMatrix()[0][j] == board.GetMatrix()[2][j] && board.GetMatrix()[0][j] == symbol)
			return { 1,j };
	}

	//checks for every row if the first and the second positions are the same
	for (uint16_t i = 0; i < 3; i++)
	{
		if (board.GetMatrix()[i][0] == board.GetMatrix()[i][1] && board.GetMatrix()[i][1] == symbol)
			return { i,2 };
	}

	//checks for every column if the first and the second positions are the same
	for (uint16_t j = 0; j < 3; j++)
	{
		if (board.GetMatrix()[0][j] == board.GetMatrix()[1][j] && board.GetMatrix()[0][j] == symbol)
			return { 2,j };
	}

	//checks for first diagonal
	if (board.GetMatrix()[0][0] == board.GetMatrix()[1][1] && board.GetMatrix()[0][0] == symbol)
		return { 2,2 };

	if (board.GetMatrix()[0][0] == board.GetMatrix()[2][2] && board.GetMatrix()[0][0] == symbol)
		return { 1,1 };

	if (board.GetMatrix()[2][2] == board.GetMatrix()[1][1] && board.GetMatrix()[1][1] == symbol)
		return { 0,0 };


	//checks for second diagonal
	if (board.GetMatrix()[0][2] == board.GetMatrix()[1][1] && board.GetMatrix()[1][1] == symbol)
		return { 2,0 };
	if (board.GetMatrix()[0][2] == board.GetMatrix()[2][0] && board.GetMatrix()[0][2] == symbol)
		return { 1,1 };
	if (board.GetMatrix()[1][1] == board.GetMatrix()[2][0] && board.GetMatrix()[1][1] == symbol)
		return { 0,2 };	

	return { -1,-1 };
}

Position Corner(Board board)
{
	if (board.GetMatrix()[0][0] == ' ')
		return { 0,0 };
	if (board.GetMatrix()[0][2] == ' ')
		return { 0,2 };
	if (board.GetMatrix()[2][0] == ' ')
		return { 2,0 };
	if (board.GetMatrix()[2][2] == ' ')
		return { 2,2 };

	return { -1,-1 };

}

Position MiddleEdge(Board board)
{
	if (board.GetMatrix()[0][1] == ' ')
		return { 0,1 };
	if (board.GetMatrix()[1][2] == ' ')
		return { 1,2 };
	if (board.GetMatrix()[2][1] == ' ')
		return { 2,1 };
	if (board.GetMatrix()[1][0] == ' ')
		return { 1,0 };

	return { -1,-1 };
}
