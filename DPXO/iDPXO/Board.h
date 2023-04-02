#pragma once
#include <array>
#include <cstdint>
#include <vector>

const size_t kWidth = 3;
const size_t kHeight = 3;

using BoardContent = std::array<std::array<char, kWidth>, kHeight>;
using Position = std::pair<int, int>;
using EmptyPositions = std::vector<Position>;

class Board
{
public:
	//Constructor
	Board();

	//Methods
	void UpdateBoard(const Position pos, const char symbol);
	Position GetRandomPosition();

	//Getters
	BoardContent GetMatrix() const;
	EmptyPositions GetEmptyPositions() const;
	
private:
	//Members
	BoardContent m_matrix;
	EmptyPositions m_emptyPos;
};
