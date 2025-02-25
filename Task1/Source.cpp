#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;


int main()
{
	const int testsToRun = 3;

	const char* testNames[testsToRun]   = {"String Constructor", "Copy Constructor", "Length"};
	bool        testResult[testsToRun] = {false, false, false};

	{
		String constructingString("I'm a String!");

		if (constructingString == "I'm a String!")
			testResult[0] = true;
	}

	{
		String testString("Test String");
		String copiedString(testString);

		if (copiedString == "Test String")
			testResult[1] = true;
	}

	{
		String lengthOfString("Numbers!");

		if (lengthOfString.Length() == 8)
			testResult[2] = true;
	}

	for (int test = 0; test < testsToRun; ++test)
	{
		std::cout
			<< "Test " << test << " " << testNames[test]
			<< " "
			<< (testResult[test] ? "Successful" : "Failed")
			<< std::endl;
	}

	// Making a test file
	std::fstream testFile;
	testFile.open("Test File.txt", ios::out);
}

