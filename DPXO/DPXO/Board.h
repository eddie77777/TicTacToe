#pragma once
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <vector>
#include <iostream>

struct PairHash {
	template <typename T1, typename T2>
	auto operator()(const std::pair<T1, T2>& p) const -> size_t {
		return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
	}
};


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

public:
	Board();

public:
	bool CheckIfAddOnPos(std::pair<uint16_t, uint16_t> pos);
	State GameState();

public:
	BoardContent GetBoardContent() const;

public:
	friend std::ostream& operator<<(std::ostream& os, const Board& board);

private:
	BoardContent m_board;
	std::unordered_set<std::pair<uint16_t, uint16_t>, PairHash> m_emptyPos;
};

