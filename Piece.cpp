/*
 * Piece.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: will
 */

#include "Piece.h"
#include <string>

Piece::Piece() {
	// TODO Auto-generated constructor stub

}

Piece::~Piece() {
	// TODO Auto-generated destructor stub
}

std::string Piece::asString() {
	switch(this->color) {
	case Piece::BLACK:
		if(this->type == Piece::KING) {
			return "B";
		}
		return "b";
	case Piece::WHITE:
		if(this->type == Piece::KING) {
			return "W";
		}
		return "w";
	}
	return "?";
}
