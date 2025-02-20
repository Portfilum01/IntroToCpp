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
	{
		newMyString[i] = myString[i];
	}

	// Adds _str elements into myNewString in front of old string 
	for (int i = 0; i < _str.lengthOfString; i++)
	{
		newMyString[lengthOfString + i] = _str.myString[i];
	}

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

int String::Replace(const char _find, const char _replace)
{
	// Declare a variable starting at 0 to count the amount of changes made
	int changesMade = 0;

	// For loop to iterate through each letter in the string
	for (int i = 0; i < lengthOfString; i++)
	{
		// If statement to say if the specified letter is found, itll replace it with the _replace letter and will add 1 to the changesMade variable
		if (myString[i] == _find)
		{
			myString[i] = _replace;
			changesMade += 1;
		}
	}

	// Returns the amount of changes made
	return changesMade;
}

String& String::ReadFromConsole()
{
	// Prints a prompt to console, then uses getline to put the user's input into myString (with a max of 80 characters
	cout << "Feed me an input (max 80 characters): " << endl;
	cin.getline(myString, 80);

	// Returns the object
	return *this;
}


String& String::WriteToConsole()
{
	// Prints myString in the object to the console
	cout << myString;
	return *this;
}


bool String::operator==(const String& _other)
{	
	// Iterates through each letter
	for (int i = 0; i <= lengthOfString; i++)
	{
		// When mismatching letters are found, it returns false.
		if (myString[i] != _other.myString[i])
		{
			return false;
		}
	}
	// Returns true if it goes out of scope (meaning no mismatches are found)
	return true;
}

char& String::operator[](size_t _index)
{
	// Detects whether or not its in range
	if (_index < 0 || _index > lengthOfString)
	{
		// Creating a variable to pass \0 as a char and return it if the above is true.
		char noReturn = '\0';
		return noReturn;
	}

	// If it is false, it will return the letter at the position specified inside of _index.
	else
	{
		return myString[_index];
	}
}

const char& String::operator[](size_t _index) const
{
	if (_index < 0 || _index > lengthOfString)
	{
		// Creating a variable to pass \0 as a char and return it if the above is true.
		char noReturn = '\0';
		return noReturn;
	}

	// If it is false, it will return the letter at the position specified inside of _index.
	else
	{
		return myString[_index];
	}
}

String& String::operator=(const String& _str)
{
	// Delete the used memory in myString
	delete[] myString;
	// Reassign enough memory to myStrijng
	myString = new char[_str.lengthOfString + 1];
	myString[_str.lengthOfString] = '\0';
	// Copy over _str's string into myString and return the object
	strcpy_s(myString, _str.lengthOfString +1, _str.myString);
	return* this;
}

bool String::operator<(const String& _str)
{
	// Stores the comparison in a variable
	int result = strcmp(myString, _str.myString);
	
	// Since a negative comparison is what we want from the strcmp, we check to see if thats what we got, if it is then return true, if not then return false.
	if (result < 0)
		return true;
	else return false;
}

