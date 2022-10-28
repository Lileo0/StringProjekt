// StringProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "String.h"
//#include "doctest.h"

int main()
{
	String s1("Hello");
	const String s2("World");
	s1 += s2;
	it = s1.begin();
	++it;
	++it;
	//std::cout << s1.c_str() << std::endl;
	std::cout << s1.begin() << std::endl;
	std::cout << *s1.begin() << std::endl;
	std::cout << s1.end() << std::endl;
	std::cout << *s1.end() << std::endl;
	const char* currentAdress = it.getAdress();
	std::cout << currentAdress << std::endl;
	std::cout << *currentAdress << std::endl;
	std::cout << &currentAdress << std::endl;
	const String test("Hello World");
	for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
	std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';
}
/*TEST_CASE("Test String Append") {
	String string1("Hello");
	String string2("World");
	string1.append(string2);
	CHECK(string1.c_str() == "HelloWorld");
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
