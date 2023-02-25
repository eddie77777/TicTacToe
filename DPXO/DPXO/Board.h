#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include <iostream>

class Board
{
public:
	static const size_t kWidth = 3;
	static const size_t kHeight = 3;
	static const size_t kSize = kWidth * kHeight;
	enum class State {
		Playing,
		Win,
		Tie
	};
	typedef std::array<std::array<char, kWidth>, kHeight> BoardContent;
	typedef std::vector<std::pair<uint16_t, uint16_t>> EmptyPositions;

public:
	Board();

public:
	bool CheckIfAddOnPos(std::pair<uint16_t, uint16_t> pos);
	State GameState();
	void SetContentOnPos(std::pair<uint16_t, uint16_t>, char symbol);
	std::pair<uint16_t, uint16_t> GetARandomEmptyPos();

public:
	BoardContent GetBoardContent() const;

public:
	friend std::ostream& operator<<(std::ostream& os, const Board& board);

private:
	BoardContent m_board;
	EmptyPositions m_emptyPos;
};

