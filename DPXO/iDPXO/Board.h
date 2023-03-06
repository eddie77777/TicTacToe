#pragma once
#include <array>
#include <cstdint>
#include <vector>

class Board
{
public:
	Board();
	
	//Static consts
	static const size_t kWidth = 3;
	static const size_t kHeight = 3;

	//Typedefs
	using BoardContent = std::array<std::array<char, kWidth>, kHeight>;
	using EmptyPositions = std::vector<std::pair<uint16_t, uint16_t>>;

	//Methods
	void UpdateBoard(const std::pair<uint16_t, uint16_t> pos, const char symbol);

	//Getters
	EmptyPositions GetEmptyPositions() const;
	BoardContent GetMatrix() const;

private:
	//Members
	BoardContent m_matrix;
	EmptyPositions m_emptyPos;
};
