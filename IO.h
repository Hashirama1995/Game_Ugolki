#pragma once
#include <utility>
#include <map>
#include <string>
#include "Cell.h"

using movePos = std::pair <Position, Position>;
using map = std::map <Position, Cell>;


class IO
{
public:
	IO();
	~IO();
	 movePos GetMove();
	 void drawBoard(const map& board);
	 std::string CastState(Cell::State state);
};