// TestCase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../TestHarness/DivideTest.h"
#include "../TestHarness/TestHarness.h"

void testCallableObj(TestHarness h, DivideTest& Objpointer);

//total number of testcase
const int TESTNUM = 5;

int main() {
	TestHarness harness(0);
	DivideTest myTest(0);

	for (int i = 0; i < TESTNUM; i++)
	{
		myTest.setValue(i);
		testCallableObj(harness, myTest);
	}
	return 0;
}

void testCallableObj(TestHarness h, DivideTest& Objpointer) {
	std::cout << "================================================\n";
	std::cout << "Calling DivideTest with divisor value = " << Objpointer.getValue() << "...\n";
	bool result = h.execObj(Objpointer);
	std::cout << "\tResult: --" << result << "--\n";
	std::cout << "================================================\n";
}