#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	// empty string
	String();

	// String constructors (a few for use in later functions
	String Object1("Hello World");

	String Object2(" Hi!");

	const String ConstantObject("Blam");

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
}

