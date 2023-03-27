#include "IStrategy.h"

class EasyStrategy : public IStrategy
{
public:
	Position GetPosition(Board board) override;
};