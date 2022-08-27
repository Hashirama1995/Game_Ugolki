#include "Game.h"
#include "Board.h"
#include "map"
#include "IO.h"
#include <iostream>
#include <stdlib.h>

Game::Game():mLastPlayer(Player::NONE),bIsSurrender(false), W_score(0), B_score(0)
{

}

Game::~Game()
{

}

Cell::State Game::getFinalCellState(Board boboard, size_t i, size_t j)
{
	Cell::State temp = boboard.getBoardCellState(i, j);
	return temp;
}


Game::Player Game::getWinner() // Ã¿– ≈– 1
{
	Player winner(Player::NONE);

	if (bIsSurrender)//œ–Œ¬≈– ¿ - —ƒ¿À—ﬂ À»?
	{
		if (mLastPlayer == Player::WHITE)
		{
			winner = Player::BLACK;
			std::cout << "*********************!!!WOW!!!************************\n" << "**************!!!BLACK CHECKERS WIN!!!!****************\n" << "****************!!!WHITE IS SURRENDER!!!**************\n";
			std::cout << std::endl << std::endl << std::endl;
			return winner;
		}
		else if (mLastPlayer == Player::BLACK)
		{
			winner = Player::WHITE;
			std::cout << "*********************!!!WOW!!!************************\n" << "**************!!!WHITE CHECKERS WIN!!!!****************\n" << "****************!!!BLACK IS SURRENDER!!!**************\n";
			std::cout << std::endl << std::endl << std::endl;
			return winner;
		}
	}
	else //(¬Õ»Ã¿Õ»≈ - ——€À¿ﬁ—‹ Õ¿ mBoard.mCells- ¬Œ«ÃŒ∆ÕŒ Õ≈ œŒ≈ƒ≈“!!!) œ–Œ¬≈– ¿ - ≈—“‹ À» —À”◊¿…, ◊“Œ ¬—≈ ÿ¿ÿ » ŒƒÕŒ√Œ Õ¿ ƒ–”√ŒÃ  –¿ﬁ
	{
		
		
		for (size_t i = 1; i < 4; i++)
		{
			for (size_t j = 6; j < 9; j++)
			{				
				Cell::State temp(getFinalCellState(mBoard,i,j));///¬Œ“ “”“
				if (temp == Cell::State::BLACK)
				{
					B_score++;
				}				
				
			}
		}

		for (size_t i = 6; i < 9; i++)
		{
			for (size_t j = 1; j < 4; j++)
			{
				Cell::State temp(getFinalCellState(mBoard, i, j));///¬Œ“ “”“
				if (temp == Cell::State::WHITE)
				{
					W_score++;
				}

			}
		}

		if (B_score == 9)
		{
			winner = Player::BLACK;
			std::cout << "*********************!!!WOW!!!************************\n" << "**************!!!BLACK CHECKERS WIN!!!!****************\n" << std::endl << std::endl << std::endl;
			return winner;
		}
		else if (W_score == 9)
		{
			winner = Player::WHITE;
			std::cout << "*********************!!!WOW!!!************************\n" << "**************!!!WHITE CHECKERS WIN!!!!****************\n" << std::endl << std::endl << std::endl;
			return winner;
		}
		else
		{
			winner = Player::NONE;
			return winner;
		}
	}
	
}



void Game::Start()
{
	mBoard.resetMap();
	auto map1 = mBoard.getMap();

	while (getWinner() == Player::NONE)
	{
		switchPlayer();
		bool direction = getDirection();

		Board::moveResult moveResult(Board::moveResult::PROHIBITED);

		while (moveResult == Board::moveResult::PROHIBITED )
		{			
			auto newMove = makeIO(direction);
			if (bIsSurrender == true)
			{
				break;
			}
			moveResult = mBoard.makeMove(newMove.first, newMove.second, direction);
		}
	}
}




bool Game::getDirection() const
{
	bool direction;
	switch (mLastPlayer)
	{
	case Player::WHITE:
		direction = false;
		break;
	case Player::BLACK:
		direction = true;
		break;
	default:
		direction = true;
		break;
	}
	return direction;
}

movePos Game::makeIO(bool direction)
{
	//Print Board
	
	system("cls");

	bool direction2 = direction;
	if (direction2 == false)
	{
		std::cout << "\_____________________________________WHITEs move!!!_____________________________________\n\n";
	}
	if (direction2 == true)
	{
		std::cout << "______________________________________BLACKs move!!!_____________________________________\n\n";
	}


	auto temp = mBoard.getMap();
	mIO.drawBoard(temp);
	//Ask for move

	movePos losePosition = { {0,0},{0,0} };
	auto newMove = mIO.GetMove();
	if (newMove == losePosition)
	{
		bIsSurrender = true;
	}
	return std::move(newMove);
}



void Game::switchPlayer()
{
	if (mLastPlayer == Player::NONE)
	{
		mLastPlayer = Player::WHITE;
	}
	else
	{
		if (mLastPlayer == Player::BLACK)
		{
			mLastPlayer = Player::WHITE;
		}
		else 
			if (mLastPlayer == Player::WHITE)
			{
				mLastPlayer = Player::BLACK;
			}
	}
}



