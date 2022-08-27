#pragma once
#include "Cell.h"
#include <map>

using map = std::map <Position, Cell>;

class Board
{
public:
	enum class moveResult{SUCCSESS_MOVE,SUCCSESS_COMBAT,PROHIBITED};

	Board();
	~Board();

	 Cell::State getBoardCellState(size_t i, size_t j);
	 Board::moveResult checkStepSide(const Position& startPos, const Position& endPos, const Position& PrewPos, Position &newTemp, Position& steps);
	void resetMap();
	moveResult makeMove(const Position& startPos, const Position& endPos, bool direction, bool forceJump=false);
	const map& getMap() const { return mCells; }

private:
	const size_t mboardSize;
	map mCells;
	moveResult checkMove(const Position& startPos, const Position& endPos, bool direction);
	moveResult checkMoveJump(const Position& startPos, const Position& endPos, const Position& Prewpos = { 0,0 });
};

