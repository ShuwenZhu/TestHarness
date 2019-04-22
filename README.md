# Project #1 - Single-User Test Harness


## Authors
Shuwen Zhu, Kevin Wren

# How to Run
Using the git plugin in Visual Studio, pull the project down.

Then Build & Run the project!

## localtime and CRT Errors
Please follow the [stack overflow guide here to fix](https://stackoverflow.com/questions/22450423/how-to-use-crt-secure-no-warnings?rq=1)

## File Description

### TestHarness.cpp & TestHarness.h

These files are our main harness, and currently the entry point into the code. Test harness defines several methods:

Name | Access | Signature | Description
--- | --- | --- | ---
TestHarness | Public | TestHarness() | Default constructor. Sets the loglevel to 0.
TestHarness | Public | TestHarness(int level) | Constructor to set the loglevel to `level`
testCallableObj | Public | bool testCallableObjs(CallObj& obj) | Takes a Callable object, and passes it into execObj. Returns pass/fail.
testCallableObjs | Public | bool testCallableObjs(std::initializer_list<CallObj> objs) | Takes multiple Callable objects, and passes it into execObjs. Returns pass/fail.
execObj | Private | bool execObj(CallObj& obj) | Wraps the object in a try/catch block, returns pass/fail depending on if we caugh an exception.
execObjs | Private | bool execObjs(std::initializer_list<CallObj> objs) | Takes a list of objecs, and passes them into execObj in order. A single fail will cause a "false" return.
currentDateTime | Private | const std::string currentDateTime() | Returns the current date/time, for logging.

### DivideTest.cpp & DivideTest.h

These files help us create exceptions by causing divide by zero exceptions, or functioning as expected.

Name |  Access |Signature | Description
--- | --- | --- | ---
DivideTest | Public | DivideTest(int a); | Our constructor. Sets the divisor.
setValue | Public | void setValue(int x); | Sets the number to be divided by.
getValue | Public | int  getValue(); | Returns the current number.
Default Operation | Public | void operator () (); | Makes this a callable object, that performs division.


## Project Description

 Developing software consisting of multiple packages requires frequent testing. If the software has complex features, we want to build it incrementally. First design and implement a very basic core with a small number of packages, then add features one-at-a-time by adding new packages, or adding a few lines of code to an existing package. Each time we add new functionality, we build and test. That way, if additions break existing code, we know where to look, e.g., in the newly added few lines of code. A test harness allows us to use that incremental process efficiently.

A test harness should allow us to define and aggregate many small tests, each of which run with exception handling and results logging. Our goal is to do that without littering our code with many try-catch blocks and many logging statements. The technique we use to do that is to define, in the test harness, an execution function that accepts a callable test object2 - function pointer, functor, or lambda - and invokes the object within the scope of a try block. A catch clause displays exceptions and returns false to indicate test failure. Otherwise the executor returns the test predicate returned by the test object, e.g., true or false for pass or fail.

The test executor also provides results logging with predefined messages. Your test harness should define several levels of loggin, e.g., just pass or fail, or more detailed, test-specific messages, or very detailed debugging messages, which display a time-date stamp and the values of key test-defined variables.

The test harness provides a mechanism to link any number of tests into a test sequence. Typically, during development, we keep adding tests for each new feature, and can rerun tests just for that feature, or all the tests of all the features, to insure that the new addition didn't break existing functionality. 

### Requirements
Your Single-User Test Harness:

    1. Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
    2. Shall provide a TestHarness class that defines an executor method, accepting any callable object that accepts no arguments3 and returns a bool predicate to indicate success or failure.
    3. The executor method Shall invoke a passed callable object in the scope of a try block. If exceptions are thrown, the catch block you define for this method shall log test failure and the contents of the exception message.
    4. Shall support linking any number of callable objects for execution, and shall provide a mechanism for executing that sequence.
    5. Shall provide a multi-level logging mechanism, intended to show:
        * just pass-fail status
        * application specific messages for pass and fail, along with the result
        * detailed debugging output that includes, on failure, values of application specific variables, and an optional time-date stamp
    6. Shall provide a sequence of tests demonstrating all the features of your TestHarness.

