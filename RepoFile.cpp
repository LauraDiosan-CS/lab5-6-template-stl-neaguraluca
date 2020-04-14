#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;


RepoFile::RepoFile():RepoTemplate<Rezervare>()
{
	fis = "";
}

RepoFile::RepoFile(const char* fileName) : RepoTemplate<Rezervare>()
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



void RepoFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++)
	{
		f << elem[i];
	}
	f.close();
}

RepoFile::~RepoFile()
{

}