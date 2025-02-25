#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;


int main()
{
	const int testsToRun = 0;

	const char* testNames[testsToRun]   = {};
	bool        testResults[testsToRun] = {};



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

