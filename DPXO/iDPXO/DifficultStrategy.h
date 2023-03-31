#pragma once
#include "MediumDifficultStrategy.h"

class DifficultStrategy : MediumDifficultStrategy
{
public:
	Position GetPosition(Board board) override;
};

