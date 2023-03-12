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
	virtual bool CheckIfAddOnPos(const std::pair<uint16_t, uint16_t> pos) const = 0;
	virtual void SetContentOnPos(const std::pair<uint16_t, uint16_t> pos, char symbol) = 0;
	virtual std::pair<uint16_t, uint16_t> GetARandomEmptyPos() const = 0;
	virtual BoardState GameState() const = 0;
};
