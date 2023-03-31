#pragma once
#include "MediumDifficultStrategy.h"

class MediumStrategy : MediumDifficultStrategy
{
public:
	Position GetPosition(Board board) override;
private:
	uint16_t m_contor = 0;
};

