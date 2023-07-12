// StringProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "String.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test String Append") {
	String string1("Hello");
	const String string2("World");
	string1.append(string2);
	String string3 = string1;
	CHECK(*string1.c_str() == *string3.c_str());
	CHECK(string1.c_str() != string3.c_str());
}

TEST_CASE("String length") {
	String string1("Hello");
	String string2("World");
	string1.append(string2);
 	CHECK(string1.length(string1.c_str()) == strlen(string1.c_str()));
	CHECK(string2.length(string2.c_str()) == strlen(string2.c_str()));
}

TEST_CASE("String Adress after append") {
	String string1("Hello");
	String string2("World");
	const char* oldAdress = string1.c_str();
	string1.append(string2);
	CHECK(string1.c_str() != oldAdress);
}

TEST_CASE("copy assignment and constructor") {
	String testString1("Hello"); 
	//const String testString2("Hello"); // Sollte so oder so nicht überschrieben werden können?
	String testString2("Hello");//const removed
	String copyString(testString1);
	testString2 = testString1;
	CHECK(testString1.c_str() != testString2.c_str());
	CHECK(testString1.c_str() != copyString.c_str());
}

TEST_CASE("move assignment and constructor") {
	String testString1("Hello");
	String testString2("World");
	const char* oldAdress = testString2.c_str();
	testString2 = std::move(testString1);
	CHECK(testString1.c_str() == nullptr); //Warning ignorierbar wegen testzwecken. Warning besagt dass move richtig deletet vom alten speicherort
	CHECK(testString2.c_str() != oldAdress);
	String moveString = std::move(testString2);
	CHECK(testString2.c_str() == nullptr);//Warning ignorierbar wegen testzwecken. Warning besagt dass move richtig deletet vom alten speicherort
	CHECK(*moveString == 'H');
}

TEST_CASE("Operator +, operator += and conversion function") {
	String s1("Hello");
	const String s2("World");
	s1 += s2;
	String s3 = s1 + s2;
	s3 += "Hello";
	String s4 = s3 + "World"; // const removed
	puts(s4);
	//CHECK(strcmp(s4.c_str(), "HelloWorldWorldHelloWorld"));
}

TEST_CASE("Sprint 4") {
	// Iteratoren
	String test("Hello World"); //Const removed
	for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
	if (std::find(test.begin(), test.end(), 'W') != test.end()) {
		CHECK(true);
	}
	else {
		CHECK(false);
	}
	//CHECK(std::find(test.begin(), test.end(), 'W') != test.end());
}
TEST_CASE("!= Test") {
	String test("Hello World"); //Const removed
	for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
	if (std::find(test.begin(), test.end(), 'Q') == test.end()) {
		CHECK(true);
	}
	else {
		CHECK(false);
	}
}