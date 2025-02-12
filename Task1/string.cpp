#include <iostream>
#include "String.h"
using namespace std;

// Creates an empty string
String::String()
{
	//int array[6];
	int* array = new int[];
	array[0] = 0;

	//delete[] array;

	// initialises string as nothing
	string string = "";
}

// Creates a string using a pointer to a C String.
String::String(const char* _str)
{
	// But not quite... as I need extra for the null terminator, right???
	int numberOfCharsINeed = strlen(_str);

	// this goes out of scope! bad!
	char* myString = new char[numberOfCharsINeed + 1];
	strcpy_s(/* need arguments */);
	
	// references the _str and makes it into a std string
}

// Constructs a string with another string
String::String(const String& _other)
{
	std::string(); 
}

// The destructor
String::~String()
{

}

