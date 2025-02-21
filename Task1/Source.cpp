#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;


int main()
{
	// Making a test file
	std::fstream testFile;
	testFile.open("Test File.txt", ios::out);
	int percentageCalculator = 0;
	string stringConstructor1 = "Test 0: Constructor Failed";

	// empty string
	String();

	// String constructors (a few for use in later functions
	String Object1("Hello World");
	if (Object1 == "Hello Wwrld")
		percentageCalculator += 1;
		stringConstructor1 = "Test 0: Constructor Successful";

	String Object2(" Hi!");
	const String ConstantObject("Test");

	//String constructed from pointing to another string
	String CopyObject(Object1);

	// Length
	Object1.Length();

	// Append
	Object1.Append(Object2);

	// Convert all to lowercase
	Object1.ToLower();

	// Convert all to uppercase
	Object1.ToUpper();

	// Find a character
	Object1.FindCharacter('O');
	
	// Replace a character
	Object1.Replace('L', 'U');

	// Read from and Write to console
	Object1.ReadFromConsole();
	CopyObject.WriteToConsole();

	// If equal to
	Object1 == Object2;
	
	// Subscript Operators
	Object1[2];
	ConstantObject[3];

	// Becomes equal to
	Object1 = Object2;

	// Less than
	Object1 < Object2;

	percentageCalculator = (percentageCalculator / 17) * 100;
	testFile << "Date: " << __DATE__ << " Time: " << __TIME__ << " " << percentageCalculator << "% of tests succeeded" << '\n' << endl;
	testFile << stringConstructor1 << endl;
}

