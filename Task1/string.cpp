#include <iostream>
#include "String.h"
using namespace std;

// Creates an empty string
String::String()
{
	string string = "";
}

// Creates a string using a pointer to a C String.
String::String(const char* _str)
{
	const char cString{};
	string string = &cString;
}

