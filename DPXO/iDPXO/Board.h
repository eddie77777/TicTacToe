#pragma once
#include <array>
#include <cstdint>
#include <vector>

const size_t kWidth = 3;
const size_t kHeight = 3;

using BoardContent = std::array<std::array<char, kWidth>, kHeight>;
using EmptyPositions = std::vector<std::pair<uint16_t, uint16_t>>;
using Pos = std::pair<uint16_t, uint16_t>;

class Board
{
public:
	Board();

	//Methods
	void UpdateBoard(const std::pair<uint16_t, uint16_t> pos, const char symbol);
	Pos GetARandomEmptyPos() const;

	//Getters
	EmptyPositions GetEmptyPositions() const;
	BoardContent GetMatrix() const;
	size_t GetMatWidth();
	size_t GetMatHeight();
	
private:
	//Members
	BoardContent m_matrix;
	EmptyPositions m_emptyPos;
};
