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
		std::cout << "The quotient is: " << dividend / divisor << std::endl;
	}
}
