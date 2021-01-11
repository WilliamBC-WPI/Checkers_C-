/*
 * Production.h
 *
 *  Created on: Oct 7, 2020
 *      Author: will
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include "Board.h"

class Production {
public:
	Production();
	virtual ~Production();

	bool prod(int argc, char* argv[]);
	Board::Direction dirString(std::string str);
};

#endif /* PRODUCTION_H_ */
