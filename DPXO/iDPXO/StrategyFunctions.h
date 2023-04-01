#pragma once
#include <cstdint>
#include <utility>
#include "Board.h"

using Position = std::pair<int, int>;

Position WinOrBlock(char Symbol, Board board);
Position MiddleEdge(Board board);
Position Corner(Board board);
