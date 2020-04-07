// UMT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include "operatii.h"
#include "teste.h"
using namespace std;
/*
int posDispensabile(string s,int pos)
{
    int nrElem = 1,i=0;
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
    int digits = 0, lCase = 0, uCase = 0,modificariA = 0,modificariD = 0,modificariR = 0,min = 0,var1 = 0,var2 = 0;
    //cin >> s;
    int modificariAV1 = 0;
    //cout << posDispensabile(s,20);
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
                cout << "copie = " << copie << endl;
                cout << "varianta 2 " << var2 << endl;
                var2 += posDispensabile(copie, copie.length());
                cout << "varianta 2 " << var2 << endl;
            }
            if (s.length() - var2 > 20)
                var2 += s.length() - 20 - var2 + modificariA;
            cout << "varianta 2 " << var2 << endl;
            return fmin(var1, var2);
        }
    }
}
*/
int main()
{
    string password;
    int nr = 0;
    test();
    cin >> password;
    cout << pass(password);
    //elimina(password,nr);
    //cout << password << " " << nr;
}