#include <iostream>
#include "Board.h"

int main()
{
	Board b;
	b.SetContentOnPos({ 0,0 }, 'x');
	b.SetContentOnPos({ 0,1 }, 'x');
	b.SetContentOnPos({ 0,2 }, 'x');
	b.SetContentOnPos({ 1,0 }, 'x');
	b.SetContentOnPos({ 1,2 }, 'x');
	std::pair<uint16_t, uint16_t >p = b.GetARandomEmptyPos();
	std::cout << b;
	std::cout << '\n';
	std::cout << p.first << ' ' << p.second;
}