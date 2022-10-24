#include "String.h"
#include <iostream>

String::String() {
	this->string = nullptr;
}

String::String(const char* givenString) { //Sollte const sein?
	string = givenString;
}

String::String(const String& other)
{
	size_t newStringLength = strlen(other.string) + 1;
	char* temp = new char[newStringLength];
	this->string = new char[newStringLength];
	strcpy_s(temp, newStringLength,other.string);
	this->string = temp;
}

String& String::operator= (const String& rhs){
	size_t newStringLength = strlen(rhs.string) + 1;
	char* temp = new char[newStringLength];
	if (this != &rhs) {
		if (this->string)
		delete[] this->string;
		this->string = new char[newStringLength];
		strcpy_s(temp, newStringLength, rhs.string);
		this->string = temp;
	}
	return *this;
}

String::String(String&& other) {
	this->string = other.string;
	other.string = nullptr;
}

String& String::operator= (String&& rhs) {
	if (this != &rhs) {
		if(this->string)
		delete[] this->string;
		this->string = rhs.string;
		rhs.string = nullptr;
	}
	return *this;
}

void String::append(const char* stringToAppend) {
	size_t newStringLength = strlen(string) + strlen(stringToAppend) + 1;
	char* temp = new char[newStringLength];
	strcpy_s(temp, newStringLength, string);
	strcat_s(temp, newStringLength, stringToAppend);
	string = temp;
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