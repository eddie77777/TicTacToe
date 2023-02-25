#pragma once
#include <array>
#include <unordered_set>
#include <cstdint>

class Board
{
public:
	static const size_t kWidth = 3;
	static const size_t kHeight = 3;
	static const size_t kSize = kWidth * kHeight;
	enum class State {
		PLAYING,
		WIN,
		TIE
	};

public:
	Board();

public:
	bool CheckIfAddOnPos(std::pair<uint16_t, uint16_t> pos);
	State GameState();

private:
	std::array<std::array<char, kWidth>, kHeight> m_board; // { { '-', '-' } };
	std::unordered_set<std::pair<uint16_t, uint16_t>> m_emptyPos;
};

