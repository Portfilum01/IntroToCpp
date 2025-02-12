#include <iostream>
#include "String.h"
using namespace std;

// Creates an empty string
String::String()
{
	// initialises string as nothing
	string string = "";
}

// Creates a string using a pointer to a C String.
String::String(const char* _str)
{
	// references the _str and makes it into a std string
	std::string() = _str;
}

// Constructs a string with another string
String::String(const String& _other)
{
	
}

// The destructor
String::~String()
{

}

