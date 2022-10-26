#pragma once
class String
{
public:
	String();
	String(const char* givenString);
	String(const String& string);
	String(String&& string);
	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	String& operator+(const String& rhs);
	String& operator+(const char* rhs);
	void append(const String& stringToAppend);
	size_t length();
	const char* c_str();
	~String();

private:
	const char* string ;
};

