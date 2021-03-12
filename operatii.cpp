/*
  A password is considered strong if below conditions are all met:  
     1. It has at least 6 characters and at most 20 characters.  
     2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.  
     3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong,
     assuming other conditions are met).  
Write an algorithm that takes a string s as input, and return the MINIMUM change required to make s a strong password. 
If s is already strong, return 0. 

Insertion, deletion or replace of any one character are all considered as one change.  

    Ideea de rezolvare :
    -verific initial conditiile pe care trebuie sa le indeplineasca o parola puternica(folosind valorile 1 si 0 pentru a stii daca e sau
    nu nevoie de a adauga o litera mare/o litera mica/o cifra pentru a indeplinii conditiile unei parole puternice,cat si variabile care retin 
    numarul modificarilor de ADD,DELETE si REPLACE(pentru a respecta sintaxa parolei puternice nu lungimea),initial declarate cu 0),iar daca acestea 
    sunt indeplinite returnez 0,altfel :
        1.Daca lungimea parolei are valoarea corecta arunci :
        -verific daca numarul elementelor dispensabile,respectiv modificari de replace(elemnte care daca sunt inlocuite nu se mai afla intr-o serie de 3 caractere identice
        consecutive,respectiv elemente incepand de la pozitia 3 intr-o subsecventa de caractere consecutive identice,din 3 in 3) este mai mare decat numarul minim de 
        caractere care ar trebui adaugate pentru a indeplinii conditiile,deoarece astfel
        acesta poate deveni 0 intrucat elementele dispensabile(Replaceable) pot fi inlocuite cu aceste caractere necesare,altfel scad din acest numar
        numarul elemntelor dispensabile folosind acelasi considerent si returnez suma modificarilor de ADD,DEELETE,REPLACE;
        2.Daca lungimea parolei este mai mica decat 6  atunci :
        -din modificarile de add scad modificarile de replace  intrucat in acest caz maximul de modificari pentru add este de 3 iar maximul
        de modificari pentru replace este de 1,astfle folosesc considerentul de mai sus,restinand astfel cat se va mai adauga lungimii initiale 
        dupa toate replace-urile
        -tot in aceste modificari voi salva maximul dintre adaosul necesar pentru a respecta sintaxa parolei puternice si adaosul necesar pentru a 
        respecta lungimea parolei puternice si returnez asemeni punctului 1
        3.Daca lungimea parolei este mai mare decat 20 atunci :
        -voi folosi doua variante de modificari pentru reducerea lungimii si o voi alege pe cea mai mica
        -prima varianta insumeaza surplusul de caractere pana la 20,numarul de elemnte replaceable si numarul de elemnte de adaugat pentru a respecta
        sintaxa(daca mai este nevoie dupa ce s-ar executa toate replace-urile)
        -a doua varianta face o copie a parolei initiale si insumeaza numarul elementelor dispensabile din copie,le sterg,adun noul numar al elementelor dispensabile
        si verific daca scazand acest numar din lungimea parolei obtin un sir cu maxim 20 de caractere sau daca mai exista elemnte dispensabile in sir,altfel continui procesul
        pe copia parolei pana cand cel putin una din cele doua conditii de mai sus este indeplinita,apoi verific daca conditia lungimii a fost satisfacuta
        iar daca nu adaug numarul minim necesar de elemnte ce trebuie sterse

*/


#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include "operatii.h"
using namespace std;

int posDispensabile(string s, int pos)
{
    int nrElem = 1, i = 0;
    int nrPosDisp = 0;
    while (i < s.length() - 1)
    {
        while (s[i] == s[i + 1] and i < pos - 1)
        {
            nrElem++;
            i++;
        }
        if (nrElem >= 3)
            nrPosDisp += nrElem / 3;
        nrElem = 1;
        i++;
    }
    return nrPosDisp;
}

int catTimpSeRepeta(string s, char c, int pos, int posEnd)
{
    int nr = 1, g = 0;
    for (int i = pos + 1; i < posEnd and g == 0; i++)
    {
        if (s[i] == c)
            nr++;
        else g = 1;
    }
    return nr;
}
void elimina(string& s, int& count)
{
    int i = 0, j, cat = 0;
    while (i < s.length())
    {
        cat = catTimpSeRepeta(s, s[i], i, s.length());
        if (cat >= 3)
        {
            for (int j = i + 2; j < i + cat; j += 2)
            {
                s.erase(j, 1);
                count++;
                cat--;
            }
        }
        i += cat;
    }

}

int pass(string s)
{
    int digits = 0, lCase = 0, uCase = 0, modificariA = 0, modificariD = 0, modificariR = 0, var1 = 0, var2 = 0;
    int modificariAV1 = 0;
    int i = 0;
    string copie;
    while (i < s.size())
    {
        if (isdigit(s[i]))
            digits = 1;
        if (islower(s[i]))
            lCase = 1;
        if (isupper(s[i]))
            uCase = 1;
        i++;
    }
    if (s.size() >= 6 and s.size() <= 20 and digits == 1 and lCase == 1 and uCase == 1
        and posDispensabile(s, s.length()) == 0)
        return 0;
    else {
        if (digits == 0)
            modificariA++;
        if (lCase == 0)
            modificariA++;
        if (uCase == 0)
            modificariA++;
        modificariR = posDispensabile(s, s.length());
        if (s.size() >= 6 and s.size() <= 20)
        {
            if (modificariR >= modificariA)
                modificariA = 0;
            else if (modificariA > modificariR)
                modificariA = modificariA - modificariR;
            return modificariA + modificariD + modificariR;
        }
        if (s.size() < 6)
        {
            modificariA -= modificariR;
            modificariA = fmax(modificariA, 6 - s.size());
            return modificariA + modificariD + modificariR;
        }
        if (s.size() > 20)
        {
            modificariAV1 = modificariA;
            if (posDispensabile(s, 20) < modificariA)
            {
                modificariAV1 -= posDispensabile(s, 20);
            }
            else if (posDispensabile(s, 20) >= modificariAV1)
            {
                modificariAV1 = 0;
            }
            var1 = s.size() - 20 + posDispensabile(s, 20) + modificariAV1;
            copie = s;
            while (posDispensabile(copie, copie.length()) > 0 and s.length() - var2 > 20)
            {
                elimina(copie, var2);
                var2 += posDispensabile(copie, copie.length());
            }
            if (s.length() - var2 > 20)
                var2 += s.length() - 20 - var2 + modificariA;
            return fmin(var1, var2);
        }
    }
}
