#pragma once
#include "MediumDifficultStrategy.h"

class DifficultStrategy : public MediumDifficultStrategy
{
public:
	Position GetPosition(Board board) override;
};

