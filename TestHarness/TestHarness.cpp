#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include <functional>
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
		std::cout << "Calling object passed into testCallableObj\n";
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
	
	// Show Lamdas work as well
	std::function<int(void)> f1 = []() { return 1; };
	std::function<int(void)> f2 = []() { throw "Oh no! My lamda threw an exception!";  return 2; };
	harness.testCallableObj(f1);
	harness.testCallableObj(f2);

	DivideTest t1(1);
	DivideTest t2(2);
	DivideTest t3(3);
	DivideTest t4(0);
	harness.testCallableObjs({ t1, t2, t3, t4 });

	// Now call on both lamdas!
	harness.testCallableObjs({ f1, f2 });
	return 0;
}
