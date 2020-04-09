#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;


RepoFile::RepoFile()
{
}

RepoFile::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nr = new char[10];
	char* tip = new char[10];
	int id;
	bool elib;
	while (!f.eof()) {
		f >> id >> nr >> tip >> elib;
		if (id >0) {
			Rezervare s(id, nr, tip, elib);
			elem.push_back(s);
		}
	}
	delete[] nr;;
	delete[] tip;
	f.close();
}

void RepoFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nr = new char[10];
	char* tip = new char[10];
	int id;
	bool elib;
	while (!f.eof()) {
		f >> id >> nr >> tip >> elib;
		if (id != 0) {
			Rezervare s(id, nr, tip, elib);
			elem.push_back(s);
		}
	}
	delete[] nr;
	delete[] tip;
	f.close();
}

/*void RepoFile::addElem(Rezervare s)
{
	elem.push_back(s);
}

Rezervare RepoFile::getById(int id)
{
	vector<Rezervare> all = getAll();
	for (Rezervare r : all)
		if (r.getID() == id)
			return r;
}

void RepoFile::delElem(int id)
{
	Rezervare rez = getById(id);
	vector < Rezervare >::iterator it;
	it = find(elem.begin(), elem.end(), rez);
	if (it != elem.end())
		elem.erase(it);
}

void RepoFile::updateElem(int id, char* nrNou, char* tipNou, bool eliberataNou)
{
	Rezervare rez = getById(id);
	rez.setNr(nrNou);
	rez.setTip(tipNou);
	rez.setEliberata(eliberataNou);
}*/

/*ector<Rezervare> RepoFile::getAll()
{
	return elem;
}

int RepoFile::size()
{
	return elem.size();
}*/

void RepoFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}

RepoFile::~RepoFile()
{

}