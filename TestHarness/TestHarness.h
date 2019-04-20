#ifndef TESTHARNESS_H
#define TESTHARNESS_H

class TestHarness {
private:
	int logLevel;
public:
	TestHarness(int level);

	//Exec method!
	template <class CallObj>
	bool execObj(CallObj& obj);
};

#endif