#include "String.h"
#include <iostream>
#include <initializer_list>

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
	String::Iterator it = &this->string[0];
	return it;
}
String::Iterator String::end()
{
	
	int i = 0;
	while (this->string[i] != '\0') {
		i++;
	}
	String::Iterator it = &this->string[i];
	//std::cout << pointer + i - 1 << std::endl;
	return it;
}

 String:: ~String() {
	 delete[] string;
}

 String::Iterator& String::Iterator::operator=(const char* pointer)
 {
	 this->currentAdress = pointer;
	 return *this;
 }

 void String::Iterator::operator++()
 {
	 // TODO: hier return-Anweisung eingeben
	 ++this->currentAdress;
 }

 void String::Iterator::operator--()
 {
	 --this->currentAdress;
 }

 bool String::Iterator::operator==(const Iterator it)
 {
	 if (this->currentAdress == it.currentAdress) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }

 bool String::Iterator::operator!=(const Iterator it)
 {
	 if (this->currentAdress != it.currentAdress) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }

 const char& String::Iterator::operator*()
 {
	 return *this->currentAdress;
 }

 const char* String::Iterator::operator->()
 {
	 return getAdress();
 }



 const char* String::Iterator::getAdress()
 {
	 return this->currentAdress;
 }

 String::Iterator::Iterator(const char* adress)
 {
	 this->currentAdress = adress;
 }
 String::Iterator::Iterator(const String::Iterator& it)
 {
	 *this = it;
 }