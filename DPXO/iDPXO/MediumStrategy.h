#include "IStrategy.h"

class MediumStrategy : public IStrategy
{
public:
	Position GetPosition(Board board) override;
private:
	uint16_t m_contor;
};