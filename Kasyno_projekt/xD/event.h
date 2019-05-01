#include "pch.h"

#include <iostream>
#include <string>
#include < conio.h>
#include <windows.h>
#include <time.h>



using namespace std;


class Event
{
	mutable int day, month, year;
	mutable int hour, minutes;
	string name;
	//lokawanie danych 
	class dodawanie
	{
		mutable float wartosc_pierwsza=0;
		mutable int wartosc_druga=0;

		int wartosc_1;
		float wartosc_2;
		int wartosc_3;
		float wartosc_4;
		long wartosc_5;
		void dodaj();

	};

public:
	Event()
	{
		name = '0';
		day = '0';
		month = '0';
		year = '0';
		hour = '0';
		minutes = '0';
		
	}

	Event(string = "PUSTO", int = 1, int = 1, int = 2019, int = 20, int = 20);

	/*Event:Event("Nic", 2, 30, 30, 30, 10)
	{

	}*/

	Event(Event & wzor)//kopiuj¹cy 
	{
		this->day = wzor.day;
		this->month = wzor.month;
		this->year = wzor.year;
		this->hour = wzor.hour;
		this->minutes = wzor.minutes;
		this->name = wzor.name;
	}

	~Event();
	int Size;
	int  wybor;
	void load();
	void show();
	void menu();
};








