#include <iostream>

class IntegerTest {
	int val;
public:
	void setValue(int x);
	int getValue();
	IntegerTest(int a);
	void operator () () {
		val++;
	};
};

IntegerTest::IntegerTest(int a) {
	val = a;
}

void IntegerTest::setValue(int x) {
	val = x;
}
int IntegerTest::getValue() {
	return val;
}