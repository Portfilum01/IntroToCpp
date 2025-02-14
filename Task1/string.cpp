#include <iostream>
#include "String.h"
using namespace std;

// makes an empty string
String::String()
{
	//takes my string and makes an array with only 1 value
	myString = new char[1];

	//Makes it into an empty string by assigning 0 to the 0th position.
	myString[0] = 0;
}

String::String(const char* _str)
{
	// Gets the length of the string
	int lengthOfString = strlen(_str);

	//Changes the size of the char array in myString
	myString = new char[lengthOfString + 1];

	// Copies the _str to myString
	strcpy_s(myString, lengthOfString, _str);
}

int main()
{
	String::String("bunger");
	cout << "YUCK!";
}
