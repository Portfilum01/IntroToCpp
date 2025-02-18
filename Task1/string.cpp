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
	for (int i = 0; i < _str.lengthOfString; i++)
		newMyString[lengthOfString + i] = _str.myString[i];

	// Deletes data stored in myString
	delete[] myString;

	// adds information from newMyString into myString.
	newMyString[tempLength] = '\0';
	myString = newMyString;

	return *this;
}

String& String::ToLower()
{
	// Creates a for loop to iterate over each letter
	for (int i = 0; i < lengthOfString; i++)
		// Checks to see if it is a capital letter on the ASCII table
		if(myString[i] >= 65 && myString[i] <= 92)
			//If it is, it'll add 32 (making it a lowercase)
			myString[i] = myString[i] + 32;

	//returns the results
	return *this;
}

String& String::ToUpper()
{
	// Creates a for loop to iterate over each letter
	for (int i = 0; i < lengthOfString; i++)
		// Checks to see if it is a lowercase letter on the ASCII table
		if (myString[i] >= 97 && myString[i] <= 122)
			//If it is, it'll remove 32 (making it an uppercase)
			myString[i] = myString[i] - 32;

	//returns the results
	return *this;
}

int String::FindCharacter(const char _chr)
{
	// creates a for loop
	for (int i = 0; i < lengthOfString; i++)
	{
		// an if statement to see if I's position is equal to _chr, then returns it if it is found.
		if (myString[i] == _chr)
			return i;
	}

	// If its not found, returns -1
	return -1;
}



// example of usage
int main()
{
	String exampleObject("Please z find my letter!");
	exampleObject.FindCharacter('z');
}
