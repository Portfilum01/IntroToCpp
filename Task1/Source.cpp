#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;


int main()
{
	const int testsToRun = 2;

	const char* testNames[testsToRun]   = {"String Constructor", "Copy Constructor"};
	bool        testResults[testsToRun] = {false, false};

	{
		String constructingString("I'm a String!");

		if (constructingString == "I'm a String!")
			testResults[0] = true;
	}


	for (int test = 0; test < testsToRun; ++test)
	{
		std::cout
			<< "Test " << test << " " << testNames[test]
			<< " "
			<< (testResults[test] ? "Successful" : "Failed")
			<< std::endl;
	}

	// Making a test file
	std::fstream testFile;
	testFile.open("Test File.txt", ios::out);
	int percentageCalculator = 0;

}

