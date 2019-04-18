#include <iostream>

class IntegerTest {
	int exceptionType;
public:
	void setValue(int x);
	int getValue();
	IntegerTest(int a);
	void operator () () {
		std::cout << "I have exceptionType: " << exceptionType << "\n";
		if (exceptionType != 0) {
			throw "Exception!";
		}
	};
};

IntegerTest::IntegerTest(int a) {
	exceptionType = a;
}

void IntegerTest::setValue(int x) {
	exceptionType = x;
}
int IntegerTest::getValue() {
	return exceptionType;
}