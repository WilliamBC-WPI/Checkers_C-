/*
 * Tests.cpp
 *
 *  Created on: Oct 12, 2020
 *      Author: will
 */

#include "Tests.h"
#include "Board.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::test() {
	bool ans = true;
	bool ok1 = testAsString();
	bool ok2 = testMove();
	ans = ok1 & ok2;
	return ans;
}


bool Tests::testAsString() {
	bool ans = true;
	Piece wk = Piece();
	wk.color = Piece::WHITE;
	wk.type = Piece::KING;
	Piece bp = Piece();
	bp.color = Piece::BLACK;
	bp.type = Piece::PAWN;
	std::string wkS = wk.asString();
	std::string bpS = bp.asString();
	if(wkS != "W")
		ans = false;
	if(bpS != "b")
		ans = false;

	return ans;
}

bool Tests::testMove() {
	bool ans = true;
	Board b = Board();
	if(b.move(16,Board::SE) == Board::INVALID) {
		ans = false;
	}
	b.move(41, Board::NE);
	if(b.move(34, Board::NW) != Board::CAPTURE) {
		ans = false;
	}
	return ans;
}
