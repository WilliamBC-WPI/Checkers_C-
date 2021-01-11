/*
 * Production.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: will
 */

#include "Production.h"
#include "Board.h"
#include "Piece.h"
#include <map>
#include <iostream>
#include <istream>

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[]) {


	//set up the game board
	//set up an instance of the map, go through assigning pieces to keys in the map that need them
	//else just put a blank board tile, with no piece.

	Board b = Board();
	std::cout << b.printBoard() << std::endl;
	int mv = 0;
	std::string d;
	int maxScore = 12;
	int whiteScore = 0;
	int blackScore = 0;
	int max = 12;
	while(whiteScore < max && blackScore < max) {
		b.move(16, Board::SE);
		std::cout << "Enter location of piece to move:" << std::endl;
		std::cin >> mv;
		std::cout << "Enter direction to move must be NE, NW, SE, SW and must be valid:" << std::endl;
		std::cin >> d;
		Board::Direction dir = dirString(d);
		Piece cp = b.gameBoard[mv];
		Board::MoveStatus boardDir  = b.move(mv, dir);
		if(boardDir != Board::INVALID) {
			b.move(mv,dir);
			if(boardDir == Board::CAPTURE) {
				if(cp.color == Piece::WHITE) {
				whiteScore++;
				}
				if(cp.color == Piece::BLACK) {
				blackScore++;
				}
			}
		}
		std::cout << b.printBoard() << std::endl;
		printf("White: %d Black: %d \n", whiteScore, blackScore);

	}


	return true;
}

Board::Direction Production::dirString(std::string str) {
	Board::Direction bd;
	if(str == "NE") {
		bd = Board::NE;
	}
	else if(str == "NW") {
		bd = Board::NW;
	}
	else if(str == "SE") {
		bd = Board::SE;
	}
	else if(str == "SW") {
		bd = Board::SW;
	}
	return bd;
}



