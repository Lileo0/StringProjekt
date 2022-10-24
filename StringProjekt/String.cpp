#include "String.h"
#include <iostream>

String::String(const char* givenString) {
	string = givenString;
	std::cout << string;
}

void String::append(const char* stringToAppend) {
	size_t newStringLength = strlen(string) + strlen(stringToAppend) + 1;
	char* temp = new char[newStringLength];
	strcpy_s(temp, newStringLength, string);
	strcat_s(temp, newStringLength, stringToAppend);
	string = temp;
	std::cout << string;
}

size_t String::length() {
	return strlen(string);
}

const char* String::c_str() {
	return this->string;
}

 String:: ~String() {
	 delete[] string;
}