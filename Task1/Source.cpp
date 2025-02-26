#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <locale.h>

using namespace std;


int main()
{
	// Declares how many tests there will be to run
	const int testsToRun = 13;

	// Makes a new array using the amount of tests to run as memory allocation
	const char* testNames[testsToRun] = { "String Constructor: ", "Copy Constructor: ", "Length: ", "Append: ", "ToLower: ", "ToUpper: ", "FindCharacter: ", "Replace: ", "Equal To Operator (==): ", "Subscript Operator: ", "Const Subscript Operator: ", "Is equal to (=): ", "Is less than"};
	bool testResult[testsToRun] = {false, false, false, false, false, false, false, false, false, false, false, false, false};

	// Initializes the percentage calculator.
	int percentageCalculator = 0;

	// For constructor string
	{
		String constructingString("I'm a String!");

		// Gets the object's string and checks if its equal to the string specified.
		if (constructingString == "I'm a String!")
		{
			testResult[0] = true;
			percentageCalculator += 1;
		}
	}

	{
		// Copy Constructor
		// Makes a string object, then copies it, and checks to see if it is equal to the original object.
		String testString("Test String");
		String copiedString(testString);

		if (copiedString == "Test String")
		{
			testResult[1] = true;
			percentageCalculator += 1;
		}
	}

	// Length function
	{
		String lengthOfString("Numbers!");

		// Gets the length of the string and compares it to the desired length
		if (lengthOfString.Length() == 8)
		{
			testResult[2] = true;
			percentageCalculator += 1;
		}
	}

	// Append
	{
		String firstString("Append ");
		String secondString("me.");
		firstString.Append(secondString);

		// Decides if the original string is equal to the new appended string.
		if (firstString == "Append me.")
		{
			testResult[3] = true;
			percentageCalculator += 1;
		}
	}

	// ToLower
	{
		String screamingString("I'M IN THE LIBRARY.");
		screamingString.ToLower();

		// Checks to see if the string has become all lowercase (Thank goodness its stopped screaming, everyone in the library had gathered their pitchforks...)
		if (screamingString == "i'm in the library.")
		{
			testResult[4] = true;
			percentageCalculator += 1;
		}
	}

	// ToUpper
	{
		String introvertString("whoo I'm at the rave");
		introvertString.ToUpper();

		// Checks to see if the string has become all uppercase (I'm so glad they started having fun at the rave)
		if (introvertString == "WHOO I'M AT THE RAVE")
		{
			testResult[5] = true;
			percentageCalculator += 1;
		}
	}

	// Find Character
	{
		String findMyF("EEEEEEEEEEEEEEEEEFEEEEEEEEEEE");

		// Checks to see if the FindCharacter actually finds the location of F
		if (findMyF.FindCharacter('F') == 17)
		{
			testResult[6] = true;
			percentageCalculator += 1;
		}
	}

	// Replace Character
	{
		String replaceEWithG("Hi, I'm E!");
		replaceEWithG.Replace('E', 'G');

		//Replaces E. sorry E, you just really sucked at Excel. 
		if (replaceEWithG == "Hi, I'm G!")
		{
			testResult[7] = true;
			percentageCalculator += 1;
		}
	}

	// Read and Write to console
	{
		String emptyString("Nothing here, odd.");
		emptyString.ReadFromConsole();
		emptyString.WriteToConsole();
	}

	// Equal To Operator
	{
		// Obligatory Game of Thrones reference
		String bestCharacter("Jon Snow");
		String bestStark("Jon Snow");

		// checks to see if best character is also the best stark (they are)
		if (bestCharacter == bestStark)
		{
			testResult[8] = true;
			percentageCalculator += 1;
		}

	}

	// Subscript operator
	{
		// Fetches the letter located at the 12th position and checks to see if it succeeded
		String alphabet("abcdefghijklmnopqrstuvwxyz");
		if (alphabet[12] == 'm')
		{
			testResult[9] = true;
			percentageCalculator += 1;
		}
	}
	
	// Same as above but for consts
	{
		const String alphabet("abcdefghijklmnopqrstuvwxyz");
		if (alphabet[12] == 'm')
		{
			testResult[10] = true;
			percentageCalculator += 1;
		}
	}

	// Is Equal To
	{
		// Makes isThisRight equal to the correct answer
		String isThisRight("Incorrect Answer");
		String correctAnswer("Correct Answer");
		isThisRight = correctAnswer;

		//Checks to see if it succeeded
		if (isThisRight == "Correct Answer")
		{
			testResult[11] = true;
			percentageCalculator += 1;
		}
	}

	// Less Than
	{
		// Checks to see if lesser is less than morer. (they should get some confidence...)
		String lesser("I'm Less");
		String morer("I'm More");
		if (lesser < morer)
		{
			testResult[12] = true;
			percentageCalculator += 1;
		}
	}

	{
		// Making a test file
		std::fstream testFile;
		testFile.open("Test File.txt", ios::app);

		// Calculates the percentage calculator.
		percentageCalculator = 100 * percentageCalculator / testsToRun;

		// Gets the callender time
		time_t time = std::time(nullptr);
		
		// Adds everything to the text file. Customized VVV the way its formatted.
		testFile << put_time(localtime(&time), "%Y %B %d, %X | ") << percentageCalculator << "% succeeded" << '\n';

		// Goes through each test and ammends it to the Test File
		for (int i = 0; i < testsToRun; ++i)
		{
			testFile
				<< "Test " << i << " " << testNames[i] << " " << (testResult[i] ? "Successful" : "Failed")
				<< " "
				<< std::endl;
		}
		testFile << '\n';
	}
}

