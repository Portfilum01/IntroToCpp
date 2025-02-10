#pragma once

class String
{
public:
	String();
	// No information, create an empty string  

	String(const char* _str);
	// Construct a string with a pointer to a c string

	String(const String& _other);
	// Construct a string with another string

	~String();
	// Destructor

public:
	size_t Length() const;
	String& Append(const String& _str);

	String& ToLower();

	String& ToUpper();
	
	int FindCharacter(const char _chr);
	
	int Replace(const char _find, const char _replace);

	String& ReadFromConsole();
	String& WriteToConsole();

	bool operator==(const String& _other);
	
	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;
	
	String& operator=(const String& _str);
	bool operator<(const String& _str);

private:
/*
* Put your internal data structures and members here
*/

};

// structs and classes
// object oriented programming/principals
// consturtors and destrcutors