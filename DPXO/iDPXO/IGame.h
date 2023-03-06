#pragma once
#include <array>
#include <cstdint>
#include <vector>

enum class BoardState {
	Playing,
	Win,
	Tie
};
static const size_t kWidth = 3;
static const size_t kHeight = 3;

class IGame
{
public:
	IGame() = default;

public:
	bool CheckIfAddOnPos(const std::pair<uint16_t, uint16_t> pos) const;
	void SetContentOnPos(const std::pair<uint16_t, uint16_t> pos, char symbol);
	std::pair<uint16_t, uint16_t> GetARandomEmptyPos() const;
	virtual BoardState GameState() const = 0;
};
