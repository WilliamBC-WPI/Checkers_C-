/*
 * Piece.h
 *
 *  Created on: Oct 7, 2020
 *      Author: will
 */

#ifndef PIECE_H_
#define PIECE_H_
#include <string>

class Piece {
public:
	Piece();
	virtual ~Piece();
	enum Color {
		WHITE = 1,
		BLACK = -1
	};
	enum Type {
		PAWN,
		KING
	};
	Type type;
	Color color;

	std::string asString();
};

#endif /* PIECE_H_ */
