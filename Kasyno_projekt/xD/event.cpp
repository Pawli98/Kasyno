#include "wydarzenie.h"

#include "pch.h"
#include "event.h"
#include <iostream>
#include <cassert> 
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4430);
using namespace std;

int Wylosowana_liczba = 0;
int podana_liczba;
int wiek = 0;
int wiek_min = 25;
int kwota_max = 10000;

class gry
{
	static int invalid;
	int input;
	static int dollars;

	// Roulette variables
	static int bet;
	char cColour;
	int iColour;
	int actualColour;

	// Slots variables
	int randSlots01;
	int randSlots02;
	int randSlots03;
	
public:
	void bankrupt();
	void roulette01();
	void roulette02();
	void rouletteWin();
	void rouletteLoss();
	void slots01();
	void slots02();
	

};


int gry::invalid = 1;
int gry::dollars = 50;
int gry::bet = 0;



void Event::load()
{
	cout << endl << "Nazwa wydarzenia:";
	cin >> name;
	cout << endl << "dzien:";
	cin >> day;
	cout << endl << "miesiac:";
	cin >> month;
	cout << endl << "godzina:";
	cin >> hour;
	cout << endl << "Minut:";
	cin >> minutes;
}


void Event::show()
{
	cout << endl << name << " " << day << "." << month << "." << year << " " << hour << ":" << minutes << endl;
}

Event::Event(string n, int d, int m, int y, int h, int mins)
{
	this->name = n;
	this->day = d;
	this->month = m;
	this->year = y;
	this->hour = h;
	this->minutes = mins;
}


Event w1("Nie ustawiono");


Event::~Event()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3); // kolory
	system("cls");
	cout << "Dziekuje za skorzystanie z programu " << endl;
	SetConsoleTextAttribute(hConsole, 15);
}


void const  logowanie() 
{
	string login, haslo;
	cout << "Podaj login:";
	cin >> login;
	cout << "Podaj haslo:";
	cin >> haslo;
	if ((login == "pawli98") && (haslo == "123456"))
	{
		cout << "Brawo zalogowales sie!";
	}
	else
	{
		cout << "Zly login lub haslo" << endl;
	}
}


void Event::dodawanie::dodaj()
{

	cin >> wartosc_pierwsza >> wartosc_druga;
	cout << wartosc_pierwsza + wartosc_druga;
}




void  const dodaj(int wartosc_1, float wartosc_2, int wartosc_3, float wartosc_4, long wartosc_5)
{
	cout << "Wartosci zetonow to:10,20,50,100,500,1000" << endl;
	cout << "Koniec wpisywania zetonow to znak: '-'" << endl;
	cout << "Max ilosc zetonow to:6" << endl;
	cout << "Podaj swoje zetony:" << endl;
	int & aa = wartosc_3;

	cin >> wartosc_1 >> wartosc_2 >> wartosc_3 >> wartosc_4 >> wartosc_5;
	cout << "Masz:";
	cout << wartosc_1 + wartosc_2 + wartosc_3 + wartosc_4 + wartosc_5 << endl;
	
}


//przyjaciel

class wymiary
{
	mutable  int szczerokosc=0;
	mutable int dlugosc=0;
	mutable int ilosc_kart = 0;
public:
	const wymiary(int a, int b);
	const wymiary(int wielkosc);
	friend class pokaz_wymiary;
};



class pokaz_wymiary
{
public:
	void  display_kosci(wymiary d1);
	void  wielkosc_taili(wymiary d2);
	
};
wymiary::wymiary(int a, int b)
{
	szczerokosc = a;
	dlugosc = b;

}

wymiary::wymiary(int wielkosc)
{
	ilosc_kart = wielkosc;
}

void pokaz_wymiary::display_kosci(wymiary d1)
{
	cout << "Wymiary stolu do gry w kosci:" << endl;
	cout << "Szerokosc stolu to:" << d1.szczerokosc << " Cm" << endl;
	cout << "Dlugosc stolu to:" << d1.dlugosc << " Cm" << endl;
}

void pokaz_wymiary::wielkosc_taili(wymiary d2)
{
	cout << "Iloœc kart w taili wynosi:" << d2.ilosc_kart << endl;
}


//Dziedziczenie
class Punkt
{
	float x, y;
	string nazwa;

public:
	void wyswietl()
	{
		cout << nazwa << "(" << x << "," << y << ")" << endl;
	}
	Punkt(string n = "S", float a = 0, float b = 0)
	{
		nazwa = n;
		x = a;
		y = b;
	}
};

class wymiary_ruletka :public Punkt //klasa wymiary_ruletka dziedziczy publicznie z klasy Punkt
{
	float r;
	string nazwa;

public:
	void wyswietl()
	{
		cout << "Nazwa: " << nazwa << endl;
		cout << "Srodek Ruletki: ";
		Punkt::wyswietl();
		cout << "Promien: " << r << "cm" << endl;

	}

	wymiary_ruletka(string nk = "Ruletka", string np = "S", float a = 0, float b = 0, float pr = 25)
		:Punkt(np, a, b)
	{
		nazwa = nk;
		r = pr;
	}
};
class wymiary_karty :public Punkt
{
	float szerokosc;
	float dlugosc;
	string nazwa;
public:
	void wyswietl()
	{
		cout << "Nazwa: " << nazwa << endl;
		cout << "Prawa krawedz stolu: ";
		Punkt::wyswietl();
		cout << "Dlugosc: " << dlugosc << "m" << endl;
		cout << "Szczerokosc: " << szerokosc << "m" << endl;
	}

	wymiary_karty(string naz = "Karty", string np = "", float a = 2, float b = 0, float szer = 2, float dl = 3)
		:Punkt(np, a, b)
	{
		nazwa = naz;
		szerokosc = szer;
		dlugosc = dl;
	}
};


//polimorfizm

class Wiek
{
public:
	virtual void min_wiek() = 0;
};


class Ruletka :public Wiek
{
	int r;
public:
	Ruletka(int x)
	{
		r = x;
	}
	virtual void min_wiek()
	{
		if (r >= 18)
			cout << "Masz ca malo lat zeby zagrac w Ruletke" << endl;
		else cout << "Mozesz grac w Ruletke" << endl;
	}
};
class karty :public Wiek
{
	int a;
public:
	karty(int x)
	{
		a = x;
	}
	virtual void min_wiek()
	{
		if (a <= 21)
			cout << "Masz ca malo lat zeby zagrac w karty" << endl;
		else cout << "Mozesz grac w Karty " << endl;
	}

};
class automaty :public Wiek
{
	int w;
public:
	automaty(int x)
	{
		w = x;
	}
	virtual void min_wiek()
	{
		if (w <= 23)
			cout << "Masz ca malo lat zeby zagrac w Automaty" << endl;
		else cout << "Mozesz grac w Automaty" << endl;
	}
};

//agregacja
class losowanie
{
protected:
	int dana_pierwsza;
public:
	void wyslij(int &dana)
	{
		dana = dana_pierwsza;
	};
	void zmieniaj(void)
	{
		dana_pierwsza = (rand() % 10);
	};
	losowanie() 
	{
		dana_pierwsza = 100;
		srand((unsigned)time(NULL));
	};
};


class wyswitlanie_los
{
	static int* ptr;
	int dana_druga;
	int i{ 7 };
public:
	void odbierz(losowanie liczba) 
	{
		liczba.wyslij(dana_druga);
		cout << " " << dana_druga << endl;
	};
	int get()
	{
		int i{ 7 };
		return i;
	}
};

class gra_kosci
{

	static wyswitlanie_los *ptr;
public:
	losowanie a1_losowanie;
	wyswitlanie_los b1_wyswietlanie;
	static int i;
	static int zwroc(){ptr->get();}
	static void stworz() { ptr = new wyswitlanie_los; }
	static void usun() { delete ptr; }

	void komunikacja(void)
	{
		//static int i ;
		int x;
		cout << "podaj";
		cin >> x;
		//int x ;

		while (i < x)
		{
			cout << " Liczba Nr:" << i;
			a1_losowanie.zmieniaj();
			b1_wyswietlanie.odbierz(a1_losowanie);
			Sleep(1);
			i++;

		}
	}
};
wyswitlanie_los *gra_kosci::ptr=0;
int gra_kosci::i = 0;

void wyswietlanie_ptr()
{
	gra_kosci::stworz();
	cout << gra_kosci::zwroc() << endl;
	gra_kosci::usun();
}


//agregazja
class Address
{
	int x;
	//string nazwa, nazawa_wydarzenia, state;
public:
	string nazwa, nazawa_wydarzenia, state;
	Address(string nazwa, string nazawa_wydarzenia, string state)
	{
		this->nazwa = nazwa;
		this->nazawa_wydarzenia = nazawa_wydarzenia;
		this->state = state;
	}
	Address (int x = 0) :x{ x } {}
	friend class date;

};

class date
{
	int *x;
	Address* address;
public:
	int wartosc;
	string name;
	date(static int val = 0) : x
	{ new int(val) } {}
	void setX(int val)
	{
		*x = val;
	}
	void print()
	{
		cout << " : " << *x << endl;
	}
	date(int wartosc, string name, Address* address)
	{
		this->wartosc = wartosc;
		this->name = name;
		this->address = address;
	}
	void display()
	{
		cout << name << " " << wartosc << " " << address->nazwa << " " << address->nazawa_wydarzenia << " " << address->state << endl;
	}
	~date()
	{
		delete address;
		delete x;
	}
	date operator= (const date& rhs)
	{
		*x = *rhs.x;
		return *this;
	}
	date& operator= (const Address& rhs)
	{
		*x = rhs.x;
		return *this;
	}
	//odwo³aæ sie do operatorów

};


void wyswietlanie_max_wygranej()
{
	Address a1 = Address("mln$.", "\n Zaparaszamy do ", "gry");
	date e1 = date(100000, "Wartosc zaplecza gotowkowego wynosi:", &a1);
	e1.display();
	system("pause");
}








//gra w wojne



void sprawdzanie_wieku()
{
	cout << "Podaj swoj wiek:";
	cin >> wiek;
	if (wiek < wiek_min)
	{
		cout << "Maxymalna kwota za ktora mozesz zagrac to:  " << kwota_max << "$" << endl;
	}
	else
	{
		cout << "Brak kwoty minimalnej za ktora mozesz zagrac " << endl;
	}
}

void Kwota_gry()
{
	int kwota = 0;
	cout << "Podaj kwote za jaka chesz zagrac:"<<endl;
	cin >> kwota;

	if (wiek_min<wiek && kwota >kwota_max)
	{
		cout << "Podana kwota jest zbut duza jak na twoj wiek" << endl;

	}

}

void losowanie_gra_wojna()
{
	srand(time(NULL));
	Wylosowana_liczba = rand() % 10;

	sprawdzanie_wieku();
	Kwota_gry();


	/*if (wiek_min < wiek)
	{*/
		cout << "Podaj liczbe od 0 do 10 " << endl;
		cin >> podana_liczba;

		if (podana_liczba > Wylosowana_liczba)
		{
			cout << "Brawo wygrales!" << endl;
			cout << "Twoja liczba to:" << podana_liczba << " Liczba przeciwnika to:" << Wylosowana_liczba << endl;

		}
		else
		{
			cout << "Przegrales! Moze uda Ci sie nastepnym razem!" << endl;
			cout << "Twoja liczba to:  " << podana_liczba << " Liczba przeciwnika to:  " << Wylosowana_liczba << endl;
		}
	/*}
	else
		cout << "Wpisz mniejsza kwote!!" << endl;*/
}


// gra w ruletke && automaty
void menu_gier();
void gry::roulette01()
{

	if (dollars <= 0)
	{
		bankrupt();
	}

	system("cls");
	cout << "\n Roulette" << endl;
	cout << endl;
	cout << " Masz: " << dollars << " dolarow!" << endl;
	cout << "\n Wcisnij 1 zeby postawic bet. Wcisnij 2 by cofnac sie do menu." << endl;
	cout << "\ Wybrano: ";
	cin >> input;
	switch (input)
	{

	case 1:
		roulette02();

	case 2:
		menu_gier();

	}
}

void gry::roulette02()
{

	cout << "\n Ile chcesz postawic na bet?" << endl;
	cout << "\Wybrano: ";
	cin >> bet;

	if (bet > dollars)
	{
		cout << "\n Nie masz tyle pieniedzy zeby obstawic!!" << endl;
		cout << "\n ";
		system("pause");
		roulette02();
	}

	cout << "\n Na co masz ochote postawic czerwone czy czarne" << endl;
	cout << "\n r to czerwone, b to  czarne" << endl;
	cout << "\n> ";
	cin >> cColour;

	if (cColour == 'r')
	{
		iColour = 1;
	}

	else {
		iColour = 2;
	}

	actualColour = rand() % 2;

	if (actualColour == iColour)
	{
		rouletteWin();
	}

	else {
		rouletteLoss();
	}

}

void  gry::rouletteWin()
{

	dollars = dollars + bet;
	cout << "\n Wygrales: " << bet << " dollars!" << endl;
	cout << "\n ";
	system("pause");
	roulette01();

}

void gry::rouletteLoss()
{

	dollars = dollars - bet;
	cout << "\n Przegrales: " << bet << " dollars!" << endl;
	cout << "\n ";
	system("pause");
	roulette01();

}

void gry::slots01()
{

	if (dollars <= 0)
	{
		bankrupt();
	}

	system("cls");
	cout << "\n Automaty" << endl;
	cout << "\n Masz: " << dollars << " dollars!" << endl;
	cout << "\n Wcisnij 1 zeby postawic bet. Wcisnij 2 by cofnac sie do menu." << endl;
	cout << "\n Wybrano: ";
	cin >> input;
	switch (input)
	{

	case 1:
		slots02();

	case 2:
		menu_gier();

	}
}

void gry::slots02()
{

	randSlots01 = rand() % 3;
	randSlots02 = rand() % 3;
	randSlots03 = rand() % 3;

	if (randSlots01 == randSlots02 && randSlots02 == randSlots03)
	{
		dollars = dollars + 10;
		cout << "\n Wygrales 10 dollars!" << endl;
		cout << "\n ";
		system("pause");
		slots01();

	}

	else {
		dollars--;
		cout << "\n Przegrales 1 dollar!" << endl;
		cout << "\n ";
		system("pause");
		slots01();
	}
}

void gry::bankrupt()
{

	cout << "\n Jestes bankrutem! Czas zaczac od nowa." << endl;
	cout << "\n ";
	system("pause");
	menu_gier();
}


//przeciaznie << oraz >>
class punkt2D
{
	int x, y;
public:
	punkt2D(int wartoscX, int wartoscY)
		:x(wartoscX), y(wartoscY)
	{

	}
	friend ostream& operator<<(ostream& out, punkt2D& punkt);
	friend istream& operator>>(istream& out, punkt2D& punkt);
};
ostream&  operator<<(ostream& out, punkt2D& punkt)
{
	out << "(" << punkt.x << ", " << punkt.y << ")";
	return out;
}
istream& operator>>(istream& in, punkt2D& punkt)
{
	in >> punkt.x;
	in >> punkt.y;
	return in;

}
void Pokaz_wielkosc()
{
	punkt2D punkt1(70, 120);

	cout<<"Czy podane pkt sa prawidlowe:" << punkt1 << endl;
	cout << "Podaj wartosi prawidlowe:";
	cin >> punkt1;

	cout <<"Podane wartosi to:"<< punkt1 << endl;
}

//prze³adowanie ++ oraz --

class Time
{

	int hours;             // 0 to 23
	int minutes;           // 0 to 59

public:
	// required constructors
	Time()
	{
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m)
	{
		hours = h;
		minutes = m;
	}
	void displayTime()
	{
		cout << "H: " << hours << ":" << minutes << endl;
	}
	void displayTime1()
	{
		cout << "H: " << hours << ":0" << minutes << endl;
	}
	Time operator++ ()
	{
		++minutes;        
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		return Time(hours, minutes);
	}

	// overloaded postfix ++ operator
	Time operator++(int)
	{
		// save the orignal value
		Time T(hours, minutes);
		++minutes;
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		return T;
	}

	Time operator-- ()
	{
		--minutes;         
		if (minutes >= 60)
		{
			--hours;
			minutes -= 60;
		}
		return Time(hours, minutes);
	}


	Time operator--(int)
	{
		Time T(hours, minutes);
		--minutes;
		if (minutes >= 60)
		{
			--hours;
			minutes -= 60;
		}
		return T;
	}

	void Displayall();



};
void Time::Displayall()
{
	Time T1(11, 59), T2(10, 40);
	cout << "Godzina w kasynie ROYAL:" << endl;
	++T1;                    // increment T1
	T1.displayTime1();        // display T1
	++T1;                    // increment T1 again
	T1.displayTime1();        // display T1


	cout << "Godzina w USA:" << endl;
	T2--;                    // increment T2
	T2.displayTime();        // display T2
	T2--;                    // increment T2 again
	T2.displayTime();        // display T2
}


//przeladowanie []

class myArray {
private:
	int size;
	int a[90000];
public:
	int& operator[] (int x)
	{
		return a[x];
	}
	void print_array();   // I included this just to show the operator[] works!  
	int w;
	void display_tab();
	int ilosc;
};

void myArray::print_array()
{
	cout << "podaj ilosc gosci:";
	cin >> w;
	for (int j = 1; j <= w; j++)
	{
		cout << "Podaj ilosc gotowki:" << endl;
		cin >> ilosc;
		cout << "Gosc nr:[" << j << "] ma: " << a[ilosc] << "$" << endl;
	}
}
void myArray::display_tab()
{

	myArray instance;
	for (int i = 0; i < 90000; i++)
		instance[i] = i;
	instance.print_array();
	cout << "\n\n";

}

//prze³adowanie ()
class Wsp_wygrana
{
	double data[2][2];
public:
	Wsp_wygrana()
	{
		for (int i = 0; i < 2; ++i)
			for (int col = 0; col < 2; ++col)
				data[i][col] = 0.0;
	}
	double& operator()(int i, int col);
};
double& Wsp_wygrana::operator()(int i, int col)
{
	assert(col >= 0 && col < 4);
	assert(i >= 0 && i < 4);
	return data[i][col];
}




//menu 2+alokacja

class Alko
{

	char rodzaj[40];
	char nazwa[40];
	int cena;

public:
	void wyswietlanie();
	void dodawanie();

};


void Alko::wyswietlanie()
{
	cout << endl;
	cout << " Rodzaj alkoholu :" << rodzaj << endl;
	cout << " Nazwa: " << nazwa << endl;
	cout << " Cena: " << cena << endl << endl;;
}
void Alko::dodawanie()
{
	cout << "podaj rodzaj alkoholu: ";
	cin >> rodzaj;
	cout << "podaj nazwe : ";
	cin >> nazwa;
	cout << "podaj cene : ";
	cin >> cena;
}



class Pracownicy
{

	char imie[40];
	char nazwisko[40];
	char ilosc_h;

public:
	void wyswietlanie();
	void dodawanie();
};


void Pracownicy::wyswietlanie()
{
	cout << endl;
	cout << " Imie :" << imie << endl;
	cout << " Nazwisko: " << nazwisko << endl;
	cout << " Ilosc przepracowanych godzin: " << ilosc_h << endl;
	cout << endl;
}
void Pracownicy::dodawanie()
{

	cout << "podaj imie: ";
	cin >> imie;
	cout << "podaj nazwisko: ";
	cin >> nazwisko;
	cout << "podaj ilosc przepracowanych godzin: ";
	cin >> ilosc_h;
}

void Alokacja1(Alko *&tab, size_t size, size_t tab_size)
{
	
	Alko *new_tab = new Alko[tab_size + size];
	for (int i = 0; i < tab_size; ++i)
	{
		new_tab[i] = tab[i];
	}

	delete[] tab;
	tab = new_tab;
}

void Alokacja2(Pracownicy** &tab, size_t size, size_t tab_size)
{
	
	Pracownicy** new_tab = new Pracownicy*[tab_size + size];

	for (size_t i = 0; i < tab_size; ++i) new_tab[i] = tab[i];
	for (size_t i = tab_size; i < tab_size + size; ++i)
	{
		
		new_tab[i] = new Pracownicy;
	}

	delete[] tab;
	tab = new_tab;
}





void usuwanko(Alko*&tab)
{
	delete[] tab;
}


void deleteBase(Pracownicy**&tab, int &licznikP)
{
	for (int i = 0; i < licznikP; i++)
	{
		delete (tab[i]);
	}
	delete[] tab;
}


void usun(Alko* &tab, size_t &tab_size, size_t ktory)
{
	if (ktory >= tab_size)
	{
		cout << "Nie ma alkoholu o takim numerze\n";
	}
	else
	{
		if (tab_size == 1)
		{
			delete[] tab;
			tab = nullptr;
			tab_size = 0;
		}
		else
		{
			Alko *new_tab = new Alko[tab_size - 1];

			for (int i = 0, j = 0; i < tab_size; i++)
			{
				if (ktory != i)
				{
					new_tab[j++] = tab[i];
				}
			}

			delete[] tab;
			tab = new_tab;
			--tab_size;
		}
	}
}


void usun(Pracownicy** &tab, size_t &tab_size, size_t ktory)
{
	if (ktory >= tab_size) 
	{
		cout << "Nie ma pracownika o takim numerze\n";
		return;
	}

	
	Pracownicy **new_tab = new Pracownicy*[tab_size];
	for (int i = 0, j = 0; i < tab_size; ++i)
	{
		if (ktory != i)
		{
			new_tab[j++] = tab[i];
		}
		else
			delete tab[i];
	}

	delete[] tab;

	tab = new_tab;
	--tab_size;


}


void dodaj(Alko* &tab, size_t &tab_size, size_t gdzie)
{
	if (gdzie > tab_size)
	{
		gdzie = tab_size;
	}

	
	Alko *new_tab = new Alko[tab_size + 1];
	for (size_t i = 0, j = 0; i < gdzie; ++i, ++j)
	{
		new_tab[j] = tab[i];
	}


	for (size_t i = gdzie, j = gdzie + 1; i < tab_size; ++i, ++j)
	{
		new_tab[j] = tab[i];
	}

	delete[] tab;
	tab = new_tab;
	++tab_size;
}


void dodaj(Pracownicy** &tab, size_t &tab_size, size_t gdzie)
{

	if (gdzie > tab_size)
	{
		gdzie = tab_size;
	}

	Pracownicy **new_tab = (Pracownicy**)malloc((tab_size + 1) * sizeof(Pracownicy*));

	for (size_t i = 0, j = 0; i < gdzie; ++i, ++j)
	{
		new_tab[j] = tab[i];
	}
	new_tab[gdzie] = new Pracownicy;
	for (size_t i = gdzie, j = gdzie + 1; i < tab_size; ++i, ++j)
	{
		new_tab[j] = tab[i];
	}



	tab = new_tab;
	++tab_size;




}


void menu();


namespace menu_pracowników
{
	void menu_obs³ugi()
	{
		HANDLE hConsole;
		size_t licznikP = 0;
		size_t ktory;
		size_t gdzie;
		size_t tab_size = 0;
		Pracownicy **tab_pracow = 0;
		Alko *tab = 0;
		int x;

		for (;;)
		{
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 14); // kolory

			cout << "MENU OBSLUGI" << endl;
			cout << "--------------" << endl;
			cout << "1.Dodaj alkohol" << endl;
			cout << "2.Dodaj pracownikow" << endl;
			cout << "3.Wyswietl alkohol" << endl;
			cout << "4.Wyswietl pracownikow" << endl;
			cout << "5.Usun alkohol" << endl;
			cout << "6.Usun Pracownika" << endl;
			cout << "7.Dodaj alokhol w wybrane miejsce" << endl;
			cout << "8.Dodaj pracownika w wybrane miejsce" << endl;
			cout << "9.Pensja" << endl;
			cout << "10.Powrot do menu glownego" << endl;

			cin >> x;
			switch (x)
			{
			case 1:
			{
				system("cls");
				cout << "Ile alkoholow chcesz dodac" << endl;
				cin >> ktory;
				Alokacja1(tab, ktory, tab_size);
				int i = tab_size;
				for (i; i < tab_size + ktory; i++)
				{
					(tab)[i].dodawanie();
				}
				tab_size += ktory;
				cout << endl;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Ilu praconikow chcesz dodac" << endl;
				cin >> ktory;
				Alokacja2(tab_pracow, ktory, licznikP);
				int i = licznikP;
				for (i; i < licznikP + ktory; i++)
				{
					(*tab_pracow)[i].dodawanie();
				}
				licznikP += ktory;
				cout << endl;
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Nasze Alkohole" << endl;
				for (int i = 0; i < tab_size; i++)
				{
					(tab)[i].wyswietlanie();
				}
				cout << endl;
				break;
			}

			case 4:
			{
				system("cls");
				cout << "Nasi pracownicy" << endl;
				for (int i = 0; i < licznikP; i++)
				{
					(*tab_pracow)[i].wyswietlanie();
				}
				break;
			}

			case 5:
			{
				system("cls");
				cout << "ktory alkohol chcesz usunac:" << endl;
				cin >> ktory;
				usun(tab, tab_size, ktory - 1);
				break;
			}
			case 6:
			{
				system("cls");
				cout << "ktorego pracownika chcesz usunac:" << endl;
				cin >> ktory;
				usun(tab_pracow, licznikP, ktory - 1);
				break;
			}
			case 7:
			{
				system("cls");
				cout << "w ktore mijsce chdesz wstawic alkohol:" << endl;
				cin >> gdzie;
				gdzie = gdzie - 1;
				dodaj(tab, tab_size, gdzie);
				(tab)[gdzie].dodawanie();
				break;
			}
			case 8:
			{
				system("cls");
				cout << "w ktore mijsce chdesz wstawic pracownikow:" << endl;
				cin >> gdzie;
				gdzie = gdzie - 1;
				dodaj(tab_pracow, tab_size, gdzie);
				(*tab_pracow)[gdzie].dodawanie();
				break;
			}
			case 9:
			{
				system("cls");
				cout << " Wyplata dla pracownikow wynosi";
				date max_wyplata(10000);
				max_wyplata.print();
				Address dodadki(5000);
				max_wyplata = dodadki;
				cout << "Dodataki ktore mozna uzyskac w ramach dobrej pracy wynosza";
				max_wyplata.print();

				break;
			}
			
			case 10:
			{
				void menu();
				//exit(0);
				return;
				break;
			}
			default:
			{
				cout << "wybrana opcja nie istnieje:" << endl << endl;
				cin >> x;
				break;
			}
			}
		}
		return;
		SetConsoleTextAttribute(hConsole, 15);
	}
}

void menu_gier();
using namespace menu_pracowników;

void Event::menu()
{
	HANDLE hConsole;

	for (;;)
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 5); // kolory
		cout << "MENU GLOWNE" << endl;
		cout << "--------------" << endl;
		cout << "1.Logowanie " << endl;
		cout << "2.Wyswietl obsluge" << endl;
		cout << "3.Najblizszy event" << endl;
		cout << "4.Policz swoje zetony" << endl;
		cout << "5.GRY" << endl;
		cout << "6.Godzina" << endl;
		cout << "7.Wiek a Gra w gry" << endl;
		cout << "8.koniec programu" << endl;
		cout << "wybierz:";

		cout << endl;
		wybor = _getch();


		switch (wybor)
		{

		case '1':
		{
			logowanie();

			break;
		}
		case '2':
		{
			system("cls");
			
			menu_obs³ugi();
			
			break;
		}
		case '3':
		{
			show();
			Sleep(1000);
			break;
		}

		case '4':
		{
			system("cls");
			dodaj(0, 0, 0, 0, 0);

			Sleep(1000);
			break;
		}
		case'5':
		{
			system("cls");
			menu_gier();
			break;
		}
		case '6':
		{
			system("cls");
			Time display;
			display.Displayall();
			break;
		}
		case '7':
		{
			Wiek *wiek[3];
			wiek[0] = new Ruletka(30);
			wiek[1] = new karty(25);
			wiek[2] = new automaty(18);
			for (int i = 0; i < 3; i++)
			{
				wiek[i]->min_wiek();
			}
			system("pause");
			break;
		}
		case '8':
			exit(0);
			break;
		default: 
			cout << "Nie ma takiej opcji w menu!";
			cout << endl;
			//getchar(); getchar();

		}

		Sleep(1000);
		system("cls");

	}
	SetConsoleTextAttribute(hConsole, 15);
}







void menu_gier()
{

	HANDLE hConsole;
	int x;
	srand(time(NULL));
	for (;;)
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 2); // kolory
		system("cls");
		cout << "MENU GIER" << endl;
		cout << "--------------" << endl;
		cout << "1.Wartosc zaplecza gotowki " << endl;
		cout << "2.Wymiary stolu do gry w kosci " << endl;
		cout << "3.Wymiary Ruletki " << endl;
		cout << "4.Wymiary stolu do gry w Karty " << endl;
		cout << "5.Generator losowych liczb do gry w kosci " << endl;
		cout << "6.Gra w wojne  " << endl;
		cout << "7.ilosc kart potrzebnych do gry w wojne " << endl;
		cout << "8.Ruletka" << endl;
		cout << "9.Ruletka-wartosci $ stol" << endl;
		cout << "10.Automaty " << endl;
		cout << "11.Wpisywanie ilosci gotowki " << endl;
		cout << "12.Powrot do menu glownego" << endl;
		

		cin >> x;
		switch (x)
		{
		case 1:
			{
			system("cls");
			wyswietlanie_max_wygranej();
			break;

			}
		case 2:
		{

			system("cls");
			wymiary wymiary_stol(80, 120);
			pokaz_wymiary pokaz;
			pokaz.display_kosci(wymiary_stol);
			Pokaz_wielkosc();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			wymiary_ruletka k1;
			k1.wyswietl();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			wymiary_karty k2;
			k2.wyswietl();
			system("pause");
			break;
		}
		case 5:
		{

			system("cls");
			gra_kosci pokaz;
			pokaz.komunikacja();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			losowanie_gra_wojna();
			break;
		}
		case 7:
		{
			system("cls");
			wymiary ilosc_kart(72);
			pokaz_wymiary pokaz;
			pokaz.wielkosc_taili(ilosc_kart);
			system("pause");
			break;
		}
		case 8:
		{
			x = 5;
			gry wyswietl_ruletka;
			wyswietl_ruletka.roulette01();
			break;
		}
		case 9:
		{
			system("cls");
			Wsp_wygrana Wsp_wygrana;
			Wsp_wygrana(1, 2) = 1000;
			Wsp_wygrana(1, 1) = 500;
			Wsp_wygrana(2, 1) = 5000;
			Wsp_wygrana(2, 2) = 10000;
			cout << " Wartosci na stole wynosza:" << endl;
			cout << "________________" << endl;
			cout << "|" << Wsp_wygrana(1, 1) << "\t| " << Wsp_wygrana(1, 2) << " |" << endl;
			cout << "|" << Wsp_wygrana(2, 1) << "\t| " << Wsp_wygrana(2, 2) << "|" << endl;
			cout << "________________" << endl;
			system("pause");
			break;
		}
		case 10:
		{
			gry wyswietl_automaty;
			wyswietl_automaty.slots01();
			break;
		}
		case 11:
		{
			system("cls");
			myArray display;
			display.display_tab();
			system("pause");
			break;
		}
		case 12:
		{
			void menu();
			//exit(0);
			return;
			break;
		}
		
		default:
		{
			cout << "wybrana opcja nie istnieje:" << endl << endl;
			cin >> x;
			break;
		}
		}
	}

	return;
	SetConsoleTextAttribute(hConsole, 15);
}