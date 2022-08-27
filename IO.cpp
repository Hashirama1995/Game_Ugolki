#include "IO.h"
#include <iostream>
#include "Cell.h"
#include <string>

IO::IO()
{
}

IO::~IO()
{
}

 movePos IO::GetMove()
{ 
    movePos position;
    size_t p1,p2;

    std::cout << "\nYou checker is:"; std::cin >> p1;
    std::cout << "\nMoving on:"; std::cin >> p2;
    std::cout << std::endl;

    position.first.first = p1 / 10;
    position.first.second = p1 - 10* position.first.first;

    position.second.first = p2 / 10;
    position.second.second = p2 - 10 * position.second.first;

    return std::move(position);
}


void IO::drawBoard(const map& board)
{
    size_t boardSize = sqrt(board.size());// Øàã 1 ïî÷åìó òî âçÿëè êîðåíü
    for (size_t i = 0; i < boardSize; i++)///ÐÀÑÑÒÀÂËßÅÌ ØÀØÊÈ!
    {
        std::cout << "|";
        for (size_t j = 0; j < boardSize; j++)
        {
            std::string cellValue= CastState(board.at(Position(i, j)).getState());// ÌÀÐÊÅÐ 2
            std::cout << cellValue;
            std::cout << "|" ;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "*****************************************************************************************\n";
    std::cout << "*                                    R  U  L  E  `s                                     *\n";
    std::cout << "*****************************************************************************************\n";
    std::cout << "WHITE MOVE FIRST!!!! \n";
    std::cout << "IF YOU WANT TO SURRENDER, ENTER <00 Enter 00>\n\n";
    std::cout << "1 STEP: Enter the height and width of the selected checker and pressed ENTER (y,x)\n";
    std::cout << "2 STEP: Enter the height and width of the desired stroke and pressed ENTER (y,x)\n";
    std::cout << "3 STEP: If the move is prohibited, try again \n";
    std::cout << "*****************************************************************************************\n";
}

std::string IO::CastState(Cell::State state)// 26:00
{
    std::string result(" ");

    switch (state)
    {
    case Cell::State::BLACK:
        result = "B";
        break;
    case Cell::State::WHITE:
        result = "W";
        break;


    case Cell::State::h1:
        result = "1";
        break;
    case Cell::State::h2:
        result = "2";
        break;
    case Cell::State::h3:
        result = "3";
        break;
    case Cell::State::h4:
        result = "4";
        break;
    case Cell::State::h5:
        result = "5";
        break;
    case Cell::State::h6:
        result = "6";
        break;
    case Cell::State::h7:
        result = "7";
        break;
    case Cell::State::h8:
        result = "8";
        break;



    case Cell::State::w0:
        result = " ";
        break;
    case Cell::State::w1:
        result = "1";
        break;
    case Cell::State::w2:
        result = "2";
        break;
    case Cell::State::w3:
        result = "3";
        break;
    case Cell::State::w4:
        result = "4";
        break;
    case Cell::State::w5:
        result = "5";
        break;
    case Cell::State::w6:
        result = "6";
        break;
    case Cell::State::w7:
        result = "7";
        break;
    case Cell::State::w8:
        result = "8";
        break;
    case Cell::State::w9:
        result = " ";
        break;

    default:
        result = " ";
        break;
    }
    return std::move(result);
}


