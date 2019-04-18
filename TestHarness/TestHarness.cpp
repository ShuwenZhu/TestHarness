// DivideTest.h: This file is the header filer for class DivideTest
// DivideTest.cpp: This file contains the implementation of DivideTest class
// Templates.h: This file contains template class that tries to call callable object and caught errors
// TestHarness.cpp : This file contains the main() 
//

#include <iostream>
#include "DivideTest.h"
#include "Templates.h"

const int TESTNUM = 5;  //total number of testcase

void testCallableObj(DivideTest&Objpointer);

int main() {
	DivideTest myTest(0);

	for (int i = 0; i < TESTNUM; i++)
	{
		myTest.setValue(i);
		testCallableObj(myTest);
	}

	/*
	IntegerTest myTest(0);
	bool result;
	std::cout << "================================================\n";
	std::cout << "Calling IntegerTest with type 0...\n";
	result = execObj(myTest);
	std::cout << "\tResult: --" << result << "--\n";
	std::cout << "================================================\n";

	myTest.setValue(5);
	std::cout << "================================================\n";
	std::cout << "Calling IntegerTest with type 5...\n";
	result = execObj(myTest);
	std::cout << "\tResult: --" << result << "--\n";
	std::cout << "================================================\n";
	system("pause");
	*/

	return 0;
}

void testCallableObj(DivideTest&Objpointer)
{
	std::cout << "================================================\n";
	std::cout << "Calling DivideTest with divisor value = " << Objpointer.getValue() << "...\n";
	bool result = execObj(Objpointer);
	std::cout << "\tResult: --" << result << "--\n";
	std::cout << "================================================\n";
}