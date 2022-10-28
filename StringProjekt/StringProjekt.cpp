// StringProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "String.h"
#include "doctest.h"

int main()
{
	String s1("Hello");
	const String s2("World");
	s1 += s2;
	String::Iterator it = s1.end();
	String::Iterator it2 = s1.begin();
	for (String::Iterator it2 = s1.begin(); it2 != s1.end(); ++it2) {
		std::cout << *it2;
	}


	//std::cout << s1.c_str() << std::endl;

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
