#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;


int main()
{
	const int testsToRun = 13;

	const char* testNames[testsToRun] = { "String Constructor: ", "Copy Constructor: ", "Length: ", "Append: ", "ToLower: ", "ToUpper: ", "FindCharacter: ", "Replace: ", "Equal To Operator (==): ", "Subscript Operator: ", "Const Subscript Operator: ", "Is equal to (=): ", "Is less than"};
	bool testResult[testsToRun] = {false, false, false, false, false, false, false, false, false, false, false, false, false};
	int percentageCalculator = 0;

	{
		String constructingString("I'm a String!");

		if (constructingString == "I'm a String!")
		{
			testResult[0] = true;
			percentageCalculator += 1;
		}
	}

	{
		String testString("Test String");
		String copiedString(testString);

		if (copiedString == "Test String")
		{
			testResult[1] = true;
			percentageCalculator += 1;
		}
	}

	{
		String lengthOfString("Numbers!");

		if (lengthOfString.Length() == 8)
		{
			testResult[2] = true;
			percentageCalculator += 1;
		}
	}

	{
		String firstString("Append ");
		String secondString("me.");
		firstString.Append(secondString);

		if (firstString == "Append me.")
		{
			testResult[3] = true;
			percentageCalculator += 1;
		}
	}

	{
		String screamingString("I'M IN THE LIBRARY.");
		screamingString.ToLower();

		if (screamingString == "i'm in the library.")
		{
			testResult[4] = true;
			percentageCalculator += 1;
		}
	}

	{
		String introvertString("whoo I'm at the rave");
		introvertString.ToUpper();

		if (introvertString == "WHOO I'M AT THE RAVE")
		{
			testResult[5] = true;
			percentageCalculator += 1;
		}
	}

	{
		String findMyF("EEEEEEEEEEEEEEEEEFEEEEEEEEEEE");

		if (findMyF.FindCharacter('F') == 17)
		{
			testResult[6] = true;
			percentageCalculator += 1;
		}
	}

	{
		String replaceEWithG("Hi, I'm E!");
		replaceEWithG.Replace('E', 'G');

		if (replaceEWithG == "Hi, I'm G!")
		{
			testResult[7] = true;
			percentageCalculator += 1;
		}
	}

	{
		//String emptyString("Nothing here, odd.");
		//emptyString.ReadFromConsole();
		//emptyString.WriteToConsole();
	}

	{
		String bestCharacter("Jon Snow");
		String bestStark("Jon Snow");
		if (bestCharacter == bestStark)
		{
			testResult[8] = true;
			percentageCalculator += 1;
		}

	}

	{
		String alphabet("abcdefghijklmnopqrstuvwxyz");
		if (alphabet[12] == 'm')
		{
			testResult[9] = true;
			percentageCalculator += 1;
		}
	}

	{
		const String alphabet("abcdefghijklmnopqrstuvwxyz");
		if (alphabet[12] == 'm')
		{
			testResult[10] = true;
			percentageCalculator += 1;
		}
	}

	{
		String isThisRight("Incorrect Answer");
		isThisRight = "Correct Answer";
		if (isThisRight == "Correct Answer")
		{
			testResult[11] = true;
			percentageCalculator += 1;
		}
	}

	{
		String lesser("I'm Less");
		String morer("I'm More");
		if (lesser < morer)
		{
			testResult[12] = true;
			percentageCalculator += 1;
		}
	}

	{

		percentageCalculator = 100 * percentageCalculator / testsToRun;
		
		cout << "Put the date here " << percentageCalculator << "% successeded" << '\n';
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
}

