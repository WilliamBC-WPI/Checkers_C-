/*
 * Board.h
 *
 *  Created on: Oct 7, 2020
 *      Author: will
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <map>
#include "Piece.h"
#include <string>

class Board {
public:
	enum Direction {NW = -1, NE = -10, SW = 1, SE = 10};
	enum MoveStatus {MOVE, INVALID, PROMOTE, CAPTURE};
	virtual ~Board();
	Board() {
	 this->size = 8;
	 	for(int row = 0; row < this->size; row++) {
	 		for(int col = 0; col < this->size; col++) {
	 			int t = row * this->size + col;
	 			if(row % 2 == 0 && row < 3) {
	 				if(t % 2 == 0) {
	 					Piece black;
	 					black.color = Piece::BLACK;
	 					black.type = Piece::PAWN;
	 					this->gameBoard[t] = black;
	 				}
	 			}
	 			if(row % 2 == 1 && row < 3) {
	 				if(t % 2 == 1) {
	 					Piece black;
	 					black.color = Piece::BLACK;
	 					black.type = Piece::PAWN;
	 					this->gameBoard[t] = black;
	 				}
	 			}
	 			if(row % 2 == 0 && row > 4) {
	 				if(t % 2 == 0) {
	 					Piece white;
	 					white.color = Piece::WHITE;
	 					white.type = Piece::PAWN;
	 					this->gameBoard[t] = white;
	 				}
	 			}
	 			if(row % 2 == 1 && row > 4) {
	 				if(t % 2 == 1) {
	 					Piece white;
	 					white.color = Piece::WHITE;
	 					white.type = Piece::PAWN;
	 					this->gameBoard[t] = white;
	 				}
	 			}
	 		}
	 	}
	};
	std::map<int, Piece> gameBoard;
	int size;

	Board::MoveStatus move(int source, Board::Direction dir);

	int offSet(int source, Board::Direction dir, int size);
	std::string printBoard();
	void createBoard();
};

#endif /* BOARD_H_ */
