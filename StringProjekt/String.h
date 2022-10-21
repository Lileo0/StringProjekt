#pragma once
class String
{
public:
	String(const char* givenString);
	void append(const char* stringToAppend);
	int length();
	const char* c_str();

private:
	const char* string ;
};

