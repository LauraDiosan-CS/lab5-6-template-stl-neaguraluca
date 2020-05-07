#include "UI.h"
#include "ServiceR.h"
#include <iostream>
using namespace std;

void UI::addUI()
{
	int id;
	char nr[10];
	char tip[10];
	char intrare[10];
	bool elib;
	cout << "Dati id-ul: ";
	cin >> id;
	cout << "Dati numarul: ";
	cin >> nr;
	cout << "Dati tipul: ";
	cin >> tip;
	cout << "Dati starea eliberarii (true/false): ";
	cin >> intrare;
	if (strcmp(intrare, "true") == 0)
		elib = true;
	else elib = false;
	serv.add(id, nr, tip, elib);
	cout << "Adaugare efectuauta!" << endl;
	cout <<endl;
}


void UI::removeUI()
{
	cout << "Dati id-ul rezervarii de sters: ";
	int id;
	cin >> id;
	serv.remove(id);
	cout << "Stergere efectuauta!" << endl;
	cout << endl;
}

void UI::updateUI()
{
	int id;
	char* nr = new char[10];
	char* tip = new char[10];
	char* intrare = new char[10];
	bool elib;
	cout << "Dati id-ul rezervarii de modificat: ";
	cin >> id;
	cout << "Dati numarul nou: ";
	cin >> nr;
	cout << "Dati tipul nou: ";
	cin >> tip;
	cout << "Dati starea noua a eliberarii (true/false): ";
	cin >> intrare;
	if (strcmp(intrare, "true") == 0)
		elib = true;
	else elib = false;
	Rezervare rez_vechi = serv.getById(id);
	//Rezervare rez_nou(id, nr, tip, elib);
	serv.update(id, nr, tip, elib);
	cout << "Modificare efectuauta!" << endl;
	cout << endl;
}




void UI::showAllUI()
{
	vector<Rezervare> rez = serv.getAll();
	for (Rezervare r : rez)
		cout << r << endl;
}

void UI::procentajUI()
{
	serv.getPercentageByType();
}


UI::UI()
{
}

UI::UI(ServiceR& s)
{
	serv = s;
}

void UI::showMenu()
{
	bool ok = false;
	while (!ok)
	{
		
		cout << "1.Adaugare rezervare" << endl;
		cout << "2.Stergere rezervare" << endl;
		cout << "3.Modificare rezervare" << endl;
		cout << "4.Afisare rezervari" << endl;
		cout << "5.Afisare procentaje" << endl;
		cout << "6.Iesire" << endl;
		cout << "------------------------"<<endl;
		cout << "Alegeti o operatie: " << endl;
		int op;
		cin >> op;
		switch (op)
		{
		case 1: {addUI(); break; };
		case 2: {removeUI(); break; };
		case 3: {updateUI(); break; };
		case 4: {showAllUI(); break; };
		case 5: {procentajUI; break; };
		case 6: {ok = true; }
		default: {cout << "Operatie inexistenta"; };

		}
	}
}

void UI::runTests()
{
	testare();
}


UI::~UI()
{
}