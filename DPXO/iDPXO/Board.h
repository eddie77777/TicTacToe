#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include "Utils.h"


const size_t kWidth = 3;
const size_t kHeight = 3;

using BoardContent = std::array<std::array<enum class ECellState, kWidth>, kHeight>;
using Position = std::pair<int, int>;
using EmptyPositions = std::vector<Position>;

class Board
{
public:
	//Constructor
	Board();

	//Methods
	void UpdateBoard(const Position pos, enum class ECellState cellState);
	Position GetRandomPosition();

	//Getters
	BoardContent GetMatrix() const;
	EmptyPositions GetEmptyPositions() const;
	
private:
	//Members
	BoardContent m_matrix;
	EmptyPositions m_emptyPos;
};
