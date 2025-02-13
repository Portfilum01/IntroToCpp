#include <iostream>
#include "String.h"
using namespace std;

// makes an empty string
String::String()
{
	//takes my string and makes an array with only 1 value
	char* myString = new char[1];

	//Makes it into an empty string by assigning 0 to the 0th position.
	myString[0] = 0;
}

String::String(const char* _str)
{
	
}

