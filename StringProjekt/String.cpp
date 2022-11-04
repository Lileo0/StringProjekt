#include "String.h"
#include <iostream>
#include <initializer_list>
using iterator_category = std::forward_iterator_tag;
using difference_type = std::ptrdiff_t;
using value_type = const char;
using pointer = const char*;  // or also value_type*
using reference = const char&;  // or also value_type&

String::String() {
	this->string = nullptr;
}

String::String(const char* givenString) { //Sollte const sein?
	size_t newStringLength = strlen(givenString) + 1;
	char* temp = new char[newStringLength];
	strcpy_s(temp, newStringLength, givenString);
	string = temp;
}

String::String(const String& other) //copyconstructor
{
	size_t newStringLength = strlen(other.string) + 1;
	char* temp = new char[newStringLength];
	this->string = new char[newStringLength];
	strcpy_s(temp, newStringLength,other.string);
	this->string = temp;
}

String& String::operator= (const String& rhs){ //copyassignment
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

String::String(String&& other) { //move constructor
	this->string = other.string;
	other.string = nullptr;
}

String& String::operator= (String&& rhs) { //move assignment
	if (this != &rhs) {
		if(this->string)
		delete[] this->string;
		this->string = rhs.string;
		rhs.string = nullptr;
	}
	return *this;
}

String& String::operator+=(const String& rhs)
{
	this->append(rhs);
	if (this != &rhs) {

	}
	return *this;
}

String& String::operator+=(const char* rhs)
{
	// TODO: hier return-Anweisung eingeben
	this->append(rhs);

	return *this;
}

char* String::operator+(const String& rhs)
{
	// TODO: hier return-Anweisung eingeben
	return add(rhs.string);
}

char* String::operator+(const char* rhs)
{
	// TODO: hier return-Anweisung eingeben
	return add(rhs);
}

void String::append(const String& stringToAppend) {
	size_t newStringLength = strlen(stringToAppend.string) + 1;
	if (this->string != nullptr) {
		newStringLength += strlen(string);
		char* temp = new char[newStringLength];
		strcpy_s(temp, newStringLength, string);
		strcat_s(temp, newStringLength, stringToAppend.string);
		delete[] string; // obsolete?
		string = temp;
	}
	else {
		char* temp = new char[newStringLength];
		strcpy_s(temp, newStringLength, stringToAppend.string);
		string = temp;
	}
}

char* String::add(const char* rhs) {
	size_t newStringLength = strlen(rhs) + 1;
	if (this->string != nullptr) {
		newStringLength += strlen(string);
		char* temp = new char[newStringLength];
		strcpy_s(temp, newStringLength, string);
		strcat_s(temp, newStringLength, rhs);
		return temp;
	}
	else {
		char* temp = new char[newStringLength];
		strcpy_s(temp, newStringLength, rhs);
		return temp;
	}
}

size_t String::length() {
	return strlen(string);
}

const char* String::c_str() {
	return this->string;
}

String::Iterator String::begin()
{
	return Iterator(&this->string[0]);
}
String::Iterator String::end()
{
	
	int i = 0;
	while (this->string[i] != '\0') {
		i++;
	}
	//std::cout << pointer + i - 1 << std::endl;
	return Iterator(&this->string[i]);;
}

 String:: ~String() {
	 delete[] string;
}


 void String::Iterator::operator++()
 {
	 // TODO: hier return-Anweisung eingeben
	 ++this->pter;
 }

 void String::Iterator::operator--()
 {
	 --this->pter;
 }

 bool String::Iterator::operator==(const Iterator it)
 {
	 if (this->pter == it.pter) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }

 bool String::Iterator::operator!=(const Iterator rhs)
 {
	 if (this->pter != rhs.pter) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }

 reference String::Iterator::operator*()
 {
	return *this->pter;
 }

 

 const char* String::Iterator::operator->()
 {
	 return getAdress();
 }



 const char* String::Iterator::getAdress()
 {
	 return this->pter;
 }
