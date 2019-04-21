#ifndef TESTHARNESS_H
#define TESTHARNESS_H
#include <initializer_list>
class TestHarness {
private:
	int logLevel;
public:
	TestHarness(int level);

	//Exec method!
	template <class CallObj>
	bool execObj(CallObj& obj);

	template <class CallObj>
	bool execObjs(std::initializer_list<CallObj> objs);

};

#endif