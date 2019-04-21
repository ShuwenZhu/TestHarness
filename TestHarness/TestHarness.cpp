#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include "DivideTest.h"
#include "TestHarness.h"

//total number of testcase
const int TESTNUM = 5;


//Test harness callable object exec call
template <class CallObj>
bool TestHarness::execObj(CallObj& obj) {
	try {
		obj();
	}
	catch (const char* msg) {
		std::cout << "\tCaught Exception: " << msg << "\n";
		return false;
	}
	catch (...) {
		std::cout << "\tCaught Exception \n ";
		return false;
	}
	return true;
}


template <class CallObj>
bool TestHarness::execObjs(std::initializer_list<CallObj> objs) {
	bool result = true;
	for (auto elem : objs) {
		if (!this->execObj(elem)) {
			result = false;
		}
	}
	return result;
}

// Constructor
TestHarness::TestHarness(int level) {
	logLevel = level;
}


void testCallableObj(TestHarness h, DivideTest&Objpointer);

int main() {
	TestHarness harness(0);
	DivideTest myTest(0);

	for (int i = 0; i < TESTNUM; i++) {
		myTest.setValue(i);
		testCallableObj(harness, myTest);
	}

	DivideTest t1(1);
	DivideTest t2(2);
	DivideTest t3(3);
	DivideTest t4(0);
	std::cout << "Now calling with multiple object calls:\n";
	std::cout << "================================================\n";
	harness.execObjs({ t1, t2, t3, t4 });
	std::cout << "================================================\n";
	std::cout << "Done!\n";
	return 0;
}

void testCallableObj(TestHarness h, DivideTest&Objpointer) {
	std::cout << "================================================\n";
	std::cout << "Calling DivideTest with divisor value = " << Objpointer.getValue() << "...\n";
	bool result = h.execObj(Objpointer);
	std::cout << "\tResult: --" << result << "--\n";
	std::cout << "================================================\n";
}