#include "pch.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>

using namespace std;

 HANDLE hConsole;

void Head()
{

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12); // kolory
	cout << "''''''''''''''''''''''''''''''''" << endl;
	cout << "'                              '" << endl;
	cout << "'       Witaj w kasynie        '" << endl;
	cout << "'           Royal              '" << endl;
	cout << "'                              '" << endl;
	cout << "''''''''''''''''''''''''''''''''" << endl;
	SetConsoleTextAttribute(hConsole, 15);
}


class Wiek
{
	mutable  unsigned int wiek = 0;
	mutable unsigned int wiek_min = 0;
	mutable  unsigned int Wylosowana_liczba = 0;
	mutable  unsigned int podana_liczba;
	
	mutable  unsigned int kwota_max = 0;
public:
	Wiek()
	{
		wiek = '0';
		wiek_min = '25';
		Wylosowana_liczba = '0';
		podana_liczba;
		kwota_max = '0';
	}


};
