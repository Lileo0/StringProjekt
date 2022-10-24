#pragma once
class String
{
public:
	String(const char* givenString);
	void append(const char* stringToAppend);
	size_t length();
	const char* c_str();
	~String();

private:
	const char* string ;
};

