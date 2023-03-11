#pragma once
#include <cstdint>
#include "IGame.h"
#include "Board.h"


class Game : public IGame
{
public:
	//Methods
	bool CheckIfAddOnPos(const std::pair<uint16_t, uint16_t> pos) const;
	void SetContentOnPos(const std::pair<uint16_t, uint16_t> pos, char symbol);
	std::pair<uint16_t, uint16_t> GetARandomEmptyPos() const;
	BoardState GameState() const;

	Board GetBoard() const;
	size_t GetMatWidth();
	size_t GetMatHeight();
	
private:
	Board m_board;
};
