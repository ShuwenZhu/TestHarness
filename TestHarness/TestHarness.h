#ifndef TESTHARNESS_H
#define TESTHARNESS_H
#include <initializer_list>
#include <time.h>
class TestHarness {
private:
	int logLevel; // 0 = Only pass/no pass; 1 = 0 + show exception message; 2 = 1 + time tag with running details

	const std::string currentDateTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		// for more information about date/time format
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

		return buf;
	}

	//Exec method!
	template <class CallObj>
	bool execObj(CallObj& obj) {
		try
		{
			obj();
		}
		catch (const char* msg) {
			if (logLevel > 1)
				std::cout << "[" << currentDateTime() << "] ";
			if (logLevel > 0)
				std::cout << "\tCaught Exception: " << msg << "\n";
			return false;
		}
		return true;
	}

	template <class CallObj>
	bool execObjs(std::initializer_list<CallObj> objs) {
		bool result = true;
		for (auto elem : objs) {
			if (!this->testCallableObj(elem)) {
				result = false;
			}
		}
		return result;
	}

public:
	TestHarness();
	TestHarness(int level);
	
	template <class CallObj>
	bool testCallableObj(CallObj& Objpointer);

	template <class CallObj>
	bool testCallableObjs(std::initializer_list<CallObj> objs);

	//destructor
	~TestHarness();

};

#endif