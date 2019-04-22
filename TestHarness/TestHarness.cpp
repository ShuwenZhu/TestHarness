#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include "DivideTest.h"
#include "TestHarness.h"

//total number of testcase
const int TESTNUM = 5;


//default constructor
TestHarness::TestHarness()
{
	logLevel = 0;
}

// Constructor
TestHarness::TestHarness(int level) {
	logLevel = level;
}

template <class CallObj>
bool TestHarness::testCallableObj(CallObj& Objpointer) {
	if (logLevel > 1)
	{
		std::cout << "================================================\n";
		std::cout << "[" << currentDateTime() << "] ";
		std::cout << "Calling DivideTest with divisor value = " << Objpointer.getValue() << "...\n";
	}
	bool result = execObj(Objpointer);
	//std::cout << "\tResult: --" << result << "--\n";
	if (result)
		std::cout << "Passed\n";
	else
		std::cout << "Failed\n";
	std::cout << "================================================\n";
	return result;
}

template <class CallObj>
bool TestHarness::testCallableObjs(std::initializer_list<CallObj> objs)
{
	if (logLevel > 1)
	{
		std::cout << "***********************************************************\n";
		std::cout << "[" << currentDateTime() << "] ";
		std::cout << "Now calling with multiple object calls:\n";
		std::cout << "***********************************************************\n";
	}
	bool result = execObjs(objs);
	if (result)
		std::cout << "Passed\n";
	else
		std::cout << "Failed\n";
	std::cout << "================================================\n";
	return result;
}

//destructor
TestHarness::~TestHarness() {};


int main() {
	TestHarness harness(2);
	DivideTest myTest(0);

	for (int i = 0; i < TESTNUM; i++) {
		myTest.setValue(i);
		harness.testCallableObj(myTest);
	}

	DivideTest t1(1);
	DivideTest t2(2);
	DivideTest t3(3);
	DivideTest t4(0);
	harness.testCallableObjs({ t1, t2, t3, t4 });

	return 0;
}
