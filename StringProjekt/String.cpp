#include "String.h"
#include <iostream>

String::String(const char* givenString) {
	string = givenString;
	std::cout << string;
}

void String::append(const char* stringToAppend) {
	int newStringLength = strlen(string) + strlen(stringToAppend) + 1;
	char* temp = new char[newStringLength];
	strcpy_s(temp, newStringLength, string);
	std::cout << temp;
	std::cout << strlen(string);
	std::cout << strlen(stringToAppend);
	strcat_s(temp, newStringLength, stringToAppend);
	string = temp;
	free(temp);
}

int String::length() {
	return strlen(string);
}

const char* String::c_str() {
	std::cout << *string;
	return this->string;
}