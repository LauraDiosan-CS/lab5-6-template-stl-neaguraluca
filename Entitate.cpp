#include "Entitate.h"
#include <cstddef>
#include <string.h>
#include <iostream>
//#include <iostream>
using namespace std;

Rezervare::Rezervare()
//constructor implicit
{
	this->id = 0;
	this->nr = NULL;
	this->tip = NULL;
	this->eliberata = false;
}

Rezervare::Rezervare(int id, const char* nr, const char* tip, bool eliberata)
/*constructor general
input: id: int, id-ul rezervarii
		nr: string, numarul camerei
		tip: string, tipul camerei
		eliberata: bool: true daca camera este libera, false in caz contrar*/
{
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->nr = new char[strlen(nr) + 1];
	strcpy_s(this->nr, strlen(nr) + 1, nr);
	this->id = id;
	this->eliberata = eliberata;
}

Rezervare::Rezervare(const Rezervare& r)
//constructor de copiere
{
	this->tip = new char[strlen(r.tip) + 1];
	strcpy_s(this->tip, strlen(r.tip) + 1, r.tip);
	this->nr = new char[strlen(r.nr) + 1];
	strcpy_s(this->nr, strlen(r.nr) + 1, r.nr);
	this->id = r.id;
	this->eliberata = r.eliberata;
}

void Rezervare::setId(int id)
/*seteaza id-ul unei rezervari
input: id: int*/
{
	this->id = id;
}

void Rezervare::setNr(char* n)
/*seteaza numarul camerei unei rezervari
input: n: string*/
{
	if (nr) delete[]nr;
	nr = new char[strlen(n) + 1];
	strcpy_s(tip, strlen(n) + 1, n);
}

void Rezervare::setTip(char* t)
/*seteaza tipul unei rezervari
input: t: string*/
{
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

void Rezervare::setEliberata(bool elib)
/*seteaza statutul camerei unei rezervari
input: elib: bool*/
{
	this->eliberata = elib;
}

Rezervare& Rezervare::operator=(const Rezervare& r)
//operator de atribuire
{
	
	this->setEliberata(r.eliberata);
	this->setId(r.id);
	this->setNr(r.nr);
	this->setTip(r.tip);
	return *this;
}

int Rezervare::getID()
//output: id-ul rezervarii
{
	return id;
}

char* Rezervare::getNr()
//output: numarul rezervarii
{
	return nr;
}

char* Rezervare::getTip()
//output: tipul rezervarii
{
	return tip;
}

bool Rezervare::getElib()
//output: starea de eliberare a rezervarii
{
	return eliberata;
}

istream& operator >>(istream& is, Rezervare& r)
//afisare
{
	int id;
	char* nr = new char[10];
	char* tip = new char[10];
	bool eliberata;
	cout << "Dati id-ul: ";
	is >> id;
	cout << "Dati numarul: ";
	is >> nr;
	cout << "Dati tipul: ";
	is >> tip;
	cout << "Dati starea eliberarii (true/ false): ";
	is >> eliberata;
	r.setId(id);
	r.setNr(nr);
	r.setTip(tip);
	r.setEliberata(eliberata);
	delete[] nr;
	delete[] tip;
	return is;
}

ostream& operator <<(ostream& os, Rezervare& c)
//citire
{
	os << "Id: " << c.id << " numar: " << c.nr << " tip: " << c.tip << " eliberata: " << c.eliberata << endl;
	return os;
}

bool Rezervare::operator==(const Rezervare& r)
{
	return (id == r.id);
}

Rezervare::~Rezervare()
//destructor
{
	id = -1;
	nr = NULL;
	tip = NULL;
	eliberata = false;
}