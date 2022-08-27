#pragma once
#include "Game.h"
#include "Board.h"
#include "map"
#include "IO.h"

class Game
{

public:
	enum class Player { NONE, BLACK, WHITE };//добавил EDGE
	Game();
	~Game();
	Player getWinner();

	void Start();
	Cell::State getFinalCellState(Board boboard,size_t i,size_t j);
	Board mBoard;

private:
	movePos makeIO(bool direction);
	bool getDirection() const;
	void switchPlayer();
	Player mLastPlayer;
	bool bIsSurrender;
	IO mIO;
	size_t W_score;
	size_t B_score;
};

