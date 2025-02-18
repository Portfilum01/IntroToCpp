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
	lengthOfString = strlen(_str);

	//Changes the size of the char array in myString
	myString = new char[lengthOfString + 1];

	// Copies the _str to myString
	strcpy_s(myString, lengthOfString + 1, _str);
}


// Construct a string with another string
String::String(const String& _other)
{
	// this gets the length of the referenced string
	lengthOfString = strlen(_other.myString);

	myString = new char[lengthOfString + 1];

	// goes through the old string and copies everything over into the new string
	for (int i = 0; i < lengthOfString; i++)
		myString[i] = _other.myString[i];
	
	// adds the null terminator to the end
	myString[lengthOfString] = '\0';
}


// String Destructor
String::~String()
{
	//Destroys the created object in myString. #freethememory...
	delete[] myString;
}


// Function to get the length of a string
size_t String::Length() const
{
	// Creates a variable and gets the length of a myString in an object
	int lengthReader = strlen(myString);

	// Returns the length of string.
	return lengthReader;
}


// Function to add a given string onto the end of string object's string.
String& String::Append(const String& _str)
{
	// Creates a new variable (myNewString) with enough memory for both strings
	int tempLength = lengthOfString + _str.lengthOfString;
	char* newMyString = new char[tempLength + 1];

	// Copies over old string info into myNewString
	for (int i = 0; i < lengthOfString; i++)
		newMyString[i] = myString[i];

	// Adds _str elements into myNewString in front of old string 
	for (int i = 0; i < tempLength; i++)
		newMyString[lengthOfString + i] = _str.myString[i];

	// Deletes data stored in myString
	delete[] myString;

	// adds information from newMyString into myString.
	newMyString[tempLength] = '\0';
	myString = newMyString;

	return *this;
}

int main()
{
	String FirstString("First");
	String SecondString("Second");
	FirstString.Append(SecondString);
}
