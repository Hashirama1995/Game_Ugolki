#include "Board.h"
#include"Cell.h"
#include <math.h>
#include <algorithm>


Board::Board():mboardSize(10)
{

}

Board::~Board()
{

}

void Board::resetMap()
{

	for (size_t i = 0; i < mboardSize; i++)
	{
		for (size_t j = 0; j < mboardSize; j++)
		{
			Cell::State state(Cell::State::BLANK);

			if (i == 0 || i==9)
			{
				switch (j)
				{

				case 1: {state = Cell::State::h1; break; }
				case 2: {state = Cell::State::h2; break; }
				case 3: {state = Cell::State::h3; break; }
				case 4: {state = Cell::State::h4; break; }
				case 5: {state = Cell::State::h5; break; }
				case 6: {state = Cell::State::h6; break; }
				case 7: {state = Cell::State::h7; break; }
				case 8: {state = Cell::State::h8; break; }

				default:
					break;
				}
			}
			

			if (j == 0 || j == 9)
			{
				switch (i)
				{
				case 0: {state = Cell::State::w0; break; }
				case 1: {state = Cell::State::w1; break; }
				case 2: {state = Cell::State::w2; break; }
				case 3: {state = Cell::State::w3; break; }
				case 4: {state = Cell::State::w4; break; }
				case 5: {state = Cell::State::w5; break; }
				case 6: {state = Cell::State::w6; break; }
				case 7: {state = Cell::State::w7; break; }
				case 8: {state = Cell::State::w8; break; }
				case 9: {state = Cell::State::w9; break; }
				default:
					break;
				}
			}

			if (i==0+1 && j==6 + 1 || i == 0 + 1 && j == 7 + 1 || i == 0 + 1 && j == 5 + 1)
			{
				state = Cell::State::WHITE;
			}
			else if (i == 1 + 1 && j == 6 + 1 || i == 1 + 1 && j == 7 + 1 || i == 1 + 1 && j == 5 + 1)
			{
				state = Cell::State::WHITE;
			}
			else if (i == 2 + 1 && j == 6 + 1 || i == 2 + 1 && j == 7 + 1 || i == 2 + 1 && j == 5 + 1)
			{
				state = Cell::State::WHITE;
			}
			
			
			
			if (i == 5 + 1 && j == 0 + 1 || i == 5 + 1 && j == 1 + 1 || i == 5 + 1 && j == 2 + 1)
			{
				state = Cell::State::BLACK;
			}
			else if (i == 6 + 1 && j == 0 + 1 || i == 6 + 1 && j == 1 + 1 || i == 6 + 1 && j == 2 + 1)
			{
				state = Cell::State::BLACK;
			}
			else if (i == 7 + 1 && j == 0 + 1 || i == 7 + 1 && j == 1 + 1 || i == 7 + 1 && j == 2 + 1)
			{
				state = Cell::State::BLACK;
			}


			Position position = Position(i, j);
			Cell cell = Cell(state);
			mCells.insert({ std::move(position), std::move(cell) });
		}
	}
}



Board::moveResult Board::checkMove(const Position& startPos, const Position& endPos, bool direction)
{
	Board::moveResult RESULT = Board::moveResult::PROHIBITED;

	const int dx = endPos.first - startPos.first;
	const int dy = endPos.second - startPos.second;
	bool isJump = false; 

	if (endPos.first >= 0 && endPos.first < mboardSize && endPos.second >= 0 && endPos.second < mboardSize)
	{
		auto targetSellState = mCells.at(endPos).getState();

		if (targetSellState ==Cell::State::BLANK)
		{

			if (abs(dx) == 2 || abs(dy) == 2)
			{
				auto startSellState = mCells.at(startPos).getState(); 
				Position victimPos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2);
				auto victimCellState = mCells.at(victimPos).getState();

				RESULT = 
					(targetSellState !=victimCellState) ? Board::moveResult::SUCCSESS_COMBAT :RESULT;
			}			
			else if ((abs(dx) == 1 || (dy == -1 )) || (abs(dx) == 1 || (dy == 1 )))
			{
				RESULT = Board::moveResult::SUCCSESS_MOVE;
			}
			

			if (abs(dx) > 2 || abs(dy) > 2)
			{
				RESULT = checkMoveJump(startPos,endPos);				
			}


		}
	}	

	return RESULT;
	
}


Board::moveResult Board::makeMove(const Position& startPos, const Position& endPos, bool direction, bool forceJump)
{
	
	auto CheckState = mCells.at(startPos).getState();
	if (CheckState == Cell::State::WHITE && direction == false || CheckState == Cell::State::BLACK && direction == true)
	{
		auto moveResult = checkMove(startPos, endPos, direction);
		switch (moveResult)
		{
		case Board::moveResult::SUCCSESS_MOVE:
			mCells.at(endPos).setState(mCells.at(startPos).getState());
			mCells.at(startPos).setState(Cell::State::BLANK);
			break;
		case Board::moveResult::SUCCSESS_COMBAT:
			mCells.at(endPos).setState(mCells.at(startPos).getState());
			mCells.at(startPos).setState(Cell::State::BLANK);
			break;
		}
		return moveResult;
	}
	else 
	{
		auto moveResult = Board::moveResult::PROHIBITED;
		return moveResult;
	}
	
}

Cell::State Board::getBoardCellState(size_t i, size_t j)
{
	Position pos(i, j);
	Cell::State tempState= mCells.at(pos).getState();
	return tempState;
}




Board::moveResult Board::checkStepSide(const Position& sPos, const Position& ePos, const Position& PrPos, Position& newTemp, Position& steps)
{

	if (sPos.first + steps.first*2 > 0 && sPos.first + steps.second*2 < 9)
	{
		if (sPos.second + steps.second*2 > 0 && sPos.second + steps.second*2 < 9)
		{
			Position First_victimPos_1((sPos.first + steps.first ), (sPos.second + steps.second ));
			Position First_targetPos_1((sPos.first + steps.first*2), (sPos.second + steps.second*2));

			auto First_victimCellState1 = mCells.at(First_victimPos_1).getState();
			auto First_targetCellState1 = mCells.at(First_targetPos_1).getState();

			if (First_victimCellState1 != Cell::State::BLANK && First_targetCellState1 == Cell::State::BLANK && First_targetPos_1 != PrPos)
			{
				newTemp = First_targetPos_1;
				if (newTemp == ePos)
				{
					return moveResult::SUCCSESS_COMBAT;
				}
			}
		}
	}	
}




Board::moveResult Board::checkMoveJump(const Position& startPos, const Position& endPos, const Position& PrewPos)
{
	auto startSellState = mCells.at(startPos).getState();
	Position tempFLAG = { 99,99 };
	Position newTemp1 = tempFLAG;
	Position newTemp2 = tempFLAG;
	Position newTemp3 = tempFLAG;
	Position newTemp4 = tempFLAG;

	Position newTemp[4] = { { 99,99 } ,{ 99,99 } ,{ 99,99 } ,{ 99,99 } };
	Position steps[4] = { {1,0},{0,1},{-1,0},{0,-1} };

	for(int i=0; i<4; i++)
	{
		checkStepSide(startPos, endPos, PrewPos, newTemp[i], steps[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (newTemp[i] == endPos)
		{
			return moveResult::SUCCSESS_COMBAT;
		}
	}
	newTemp1 = newTemp[0];
	newTemp2 = newTemp[1];
	newTemp3 = newTemp[2];
	newTemp4 = newTemp[3];



	if (newTemp1 != tempFLAG || newTemp2 != tempFLAG || newTemp3 != tempFLAG || newTemp4 != tempFLAG)
	{
		int dx1 = (newTemp1.first - endPos.first); int dy1 = (newTemp1.second - endPos.second);
		int dx2 = (newTemp2.first - endPos.first); int dy2 = (newTemp2.second - endPos.second);
		int dx3 = (newTemp3.first - endPos.first); int dy3 = (newTemp3.second - endPos.second);
		int dx4 = (newTemp4.first - endPos.first); int dy4 = (newTemp4.second - endPos.second);

		int raznost1 = abs(dx1) + abs(dy1);
		int raznost2 = abs(dx2) + abs(dy2);
		int raznost3 = abs(dx3) + abs(dy3);
		int raznost4 = abs(dx4) + abs(dy4);
		int dontValid = 186;

		if (raznost1 < raznost2 && raznost1 < raznost3 && raznost1 < raznost4)
		{
			return checkMoveJump(newTemp1, endPos, startPos);
		}
		if (raznost2 < raznost1 && raznost2 < raznost3 && raznost2 < raznost4)
		{
			return checkMoveJump(newTemp2, endPos, startPos);
		}
		if (raznost3 < raznost1 && raznost3 < raznost2 && raznost3 < raznost4)
		{
			return checkMoveJump(newTemp3, endPos, startPos);
		}
		if (raznost4 < raznost1 && raznost4 < raznost2 && raznost4 < raznost3)
		{
			return checkMoveJump(newTemp4, endPos, startPos);
		}



		if (raznost1 == raznost2 && raznost1 != dontValid) 
		{
			Board::moveResult check1 = checkMoveJump(newTemp1, endPos, startPos);
			Board::moveResult check2 = checkMoveJump(newTemp2, endPos, startPos);
			if (check1 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check1;
			}
			else if (check2 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check2;
			}

		}
		if (raznost1 == raznost3 && raznost1 != dontValid)
		{
			Board::moveResult check1 = checkMoveJump(newTemp1, endPos, startPos);
			Board::moveResult check3 = checkMoveJump(newTemp3, endPos, startPos);
			if (check1 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check1;
			}
			else if (check3 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check3;
			}
		}
		if (raznost1 == raznost4 && raznost1 != dontValid)
		{
			Board::moveResult check1 = checkMoveJump(newTemp1, endPos, startPos);
			Board::moveResult check4 = checkMoveJump(newTemp4, endPos, startPos);
			if (check1 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check1;
			}
			else if (check4 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check4;
			}
		}



		if (raznost2 == raznost3 && raznost2 != dontValid)
		{
			Board::moveResult check2 = checkMoveJump(newTemp2, endPos, startPos);
			Board::moveResult check3 = checkMoveJump(newTemp3, endPos, startPos);
			if (check2 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check2;
			}
			else if (check3 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check3;
			}
		}
		if (raznost2 == raznost4 && raznost2 != dontValid)
		{
			Board::moveResult check2 = checkMoveJump(newTemp2, endPos, startPos);
			Board::moveResult check4 = checkMoveJump(newTemp4, endPos, startPos);
			if (check2 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check2;
			}
			else if (check4 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check4;
			}
		}

		if (raznost3 == raznost4 && raznost3 != dontValid)
		{
			Board::moveResult check3 = checkMoveJump(newTemp3, endPos, startPos);
			Board::moveResult check4 = checkMoveJump(newTemp4, endPos, startPos);
			if (check3 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check3;
			}
			else if (check4 == Board::moveResult::SUCCSESS_COMBAT)
			{
				return check4;
			}
		}

	}
}