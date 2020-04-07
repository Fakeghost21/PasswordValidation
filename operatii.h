#include <iostream>
using namespace std;
/*
	returneaza numarul pozitiilor dispensabile incepand de la o anumita pozitie dintr-un string
*/
int posDispensabile(string s, int pos);

/*
	returneaza numarul repetarilor consecutive ale unui caracter intr-un interval dintr-un string
*/
int catTimpSeRepeta(string s, char c, int pos, int posEnd);

/*
	transmite prin referinta un string-ul schimbat dupa ce din acesta sau eliminat primele elemente dispensabile,cat si numarul eliminarilor
*/
void elimina(string& s, int& count);

/*
	returneaza 0 daca string-ul introdus reprezinta o parola puternica sau numarul minim de schimbari necesare altfel
*/
int pass(string s);
