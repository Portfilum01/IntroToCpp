#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;


int main()
{
	const int testsToRun = 7;

	const char* testNames[testsToRun] = { "String Constructor", "Copy Constructor", "Length", "Append", "ToLower", "ToUpper", "FindCharacter"};
	bool testResult[testsToRun] = {false, false, false, false, false, false, false};

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

	{
		String firstString("Append ");
		String secondString("me.");
		firstString.Append(secondString);
		
		if (firstString == "Append me.")
			testResult[3] = true;
	}

	{
		String screamingString("I'M IN THE LIBRARY.");
		screamingString.ToLower();

		if (screamingString == "i'm in the library.")
			testResult[4] = true;
	}

	{
		String introvertString("whoo I'm at the rave");
		introvertString.ToUpper();

		if (introvertString == "WHOO I'M AT THE RAVE")
			testResult[5] = true;
	}

	{
		String findMyF("EEEEEEEEEEEEEEEEEFEEEEEEEEEEE");

		if (findMyF.FindCharacter('F') == 17)
			testResult[6] = true;
	}

	for (int i = 0; i < testsToRun; ++i)
	{
		std::cout
			<< "Test " << i << " " << testNames[i]
			<< " "
			<< (testResult[i] ? "Successful" : "Failed")
			<< std::endl;
	}

	// Making a test file
	std::fstream testFile;
	testFile.open("Test File.txt", ios::out);
}

