/*
 * Board.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: will
 */

#include "Board.h"
#include "Piece.h"
#include <string>
#include <map>

//Board::Board() {
//	// TODO Auto-generated constructor stub
//
//}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

Board::MoveStatus Board::move(int source, Board::Direction dir) {
	if(gameBoard.count(source) == 0) {
		return INVALID;
	}
	Piece sourcePiece = this->gameBoard[source];
	if(sourcePiece.type == Piece::PAWN && sourcePiece.color * dir > 0) {
		return INVALID;
	}
	int target = Board::offSet(source, dir, this->size);
	if(target > this->size * this->size || target < 0) {
		return INVALID;
	}
	if(this->gameBoard.count(target) == 0) {
		MoveStatus val = MOVE;
		if(sourcePiece.type != Piece::KING &&
				 ((sourcePiece.color == Piece::BLACK && target <= this->size - 1) ||
				  (sourcePiece.color == Piece::WHITE && target >= (this->size - 1) * this->size))) {
			sourcePiece.type = Piece::KING;
			val = PROMOTE;
		}
		gameBoard[target] = sourcePiece;
		gameBoard.erase(source);
		return val;
	}

	Piece targetPiece = this->gameBoard[target];
	if(sourcePiece.color == targetPiece.color) {
		return INVALID;
	}
	int captureTarget = Board::offSet(target, dir, this->size);

	if(captureTarget > this->size * this->size || captureTarget < 0 || this->gameBoard.count(captureTarget) != 0) {
		return INVALID;;
	}

	gameBoard[captureTarget] = sourcePiece;
	gameBoard.erase(target);
	gameBoard.erase(source);

	// TODO: What happens if the capture target is on the promotion row?
	if(sourcePiece.type != Piece::KING &&
					 ((sourcePiece.color == Piece::BLACK && target <= this->size - 1) ||
					  (sourcePiece.color == Piece::WHITE && target >= (this->size - 1) * this->size))){
		sourcePiece.type = Piece::KING;
	}
	return CAPTURE;
}

int Board::offSet(int source, Board::Direction dir, int size) {
	int colOffset;
	switch(dir) {
	case NE:
	case SE:
		colOffset = 1;
		break;
	case NW:
	case SW:
		colOffset = -1;
		break;
	}
	return source + ((dir%9) * size) + (std::abs(dir%9) * colOffset);
}

std::string Board::printBoard() {
	std::string board;
		for(int row = 0; row < this->size; row++){
			board +="\n";
			for(int col = 0; col < this->size; col++) {
				int target = (row * this->size) + col;
				if(this->gameBoard.count(target)) {
					board += this->gameBoard[target].asString();
					continue;
				}
				if((row + col) % 2) {
					board += "+";
					continue;
				}
				board +="-";
			}
		}
		return board;
}

