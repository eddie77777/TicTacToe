#pragma once
#include <array>
#include <set>

class Board
{
public:
	static const size_t kWidth = 3;
	static const size_t kHeight = 3;
	static const size_t kSize = kWidth * kHeight;

public:
	Board() = default;

public:
	bool CheckIfAddOnPos();
	bool WinOrDraw();

private:
	std::array<std::array<char, kWidth>, kHeight> m_board;
	std::set<std::pair<uint16_t, uint16_t>> m_emptyPos;
	enum class States {
		NONE,
		WIN,
		TIE
	};
};

