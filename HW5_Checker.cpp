//============================================================================
// Name        : HW5_Checker.cpp
// Author      : BAZAKAS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tests.h"
#include "Production.h"
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Tests* tsp = new Tests;
	if(tsp->test()) {
		Production* pP = new Production();
		if(pP->prod(argc, argv)) {
			cout << "Running Production" << endl;
		delete pP;
		}
	}
	else {
		cout << "Tests failed" << endl;
	}
	return 0;
}
