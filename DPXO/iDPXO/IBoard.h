#pragma once
#pragma once
#include <array>
#include <cstdint>
#include <vector>

class IBoard
{
public:
	IBoard() = default;

public:
	virtual bool CheckIfAddOnPos(std::pair<uint16_t, uint16_t> pos) = 0;
	virtual void SetContentOnPos(std::pair<uint16_t, uint16_t>, char symbol) = 0;
	virtual std::pair<uint16_t, uint16_t> GetARandomEmptyPos() = 0;
};
