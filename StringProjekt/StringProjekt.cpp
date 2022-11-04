// StringProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "String.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


/*int main()
{
	String s1("Hello");
	const String s2("World");
	s1 += s2;
	String::Iterator it = s1.end();
	String::Iterator it2 = s1.begin();
	for (String::Iterator it2 = s1.begin(); it2 != s1.end(); ++it2) {
		std::cout << *it2;
	}
	std::cout<< (std::find(s1.begin().getAdress(), s1.end().getAdress(), 'Q') != s1.end().getAdress());


	//std::cout << s1.c_str() << std::endl;

}*/
TEST_CASE("Test String Append") {
	String string1("Hello");
	const String string2("World");
	string1.append(string2);
	String string3 = string1;
	CHECK(*string1.c_str() == *string3.c_str());
}

TEST_CASE("String length") {
	String string1("Hello");
	String string2("World");
	string1.append(string2);
	CHECK(string1.length(string1.c_str()) == 10);
	CHECK(string2.length(string2.c_str()) == 5);
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
	CHECK(testString1.c_str() == nullptr);
	CHECK(testString2.c_str() != oldAdress);
	String moveString = std::move(testString2);
	CHECK(testString2.c_str() == nullptr);
	CHECK(*moveString == 'H');
}

TEST_CASE("Operator +, operator += and conversion function") {
	String s1("Hello");
	const String s2("World");
	s1 += s2;
	String s3 = s1 + s2;
	s3 += "Hello";
	String s4 = s3 + "World"; // const removed
	std::cout << s1.c_str()<< std::endl;
	puts(s4);
	CHECK(true);
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

/*TEST_CASE("Const tests") {
	String testString1("Hello");
	const String testString2("Hello");
	String copyString(testString1);
	testString2 = testString1;
	std::cout << copyString.c_str();
}*/
// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
