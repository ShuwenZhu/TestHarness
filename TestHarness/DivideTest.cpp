// DivideTest.h: This file is the header filer for class DivideTest
// DivideTest.cpp: This file contains the implementation of DivideTest class
// Templates.h: This file contains template class that tries to call callable object and caught errors
// TestHarness.cpp : This file contains the main() 
//
#include "DivideTest.h"

DivideTest::DivideTest(int a) {
	divisor = a;
}

void DivideTest::setValue(int x) {
	divisor = x;
}
int DivideTest::getValue() {
	return divisor;
}

void DivideTest::operator() () {
	if (divisor == 0)
	{
		throw "Divided by zero exception!";
	}
	else
	{
		std::cout << "Done, the quotient is: " << dividend / divisor << std::endl;
	}
}
