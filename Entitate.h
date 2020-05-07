#pragma once
#include <istream>
#include <ostream>
#include <string>
using namespace std;

class Rezervare
{
private:
	int id;
	char* nr;
	char* tip;
	bool eliberata;
public:
	Rezervare();
	Rezervare(int, const char*, const char*, bool);
	Rezervare(const Rezervare&);
	Rezervare& operator=(const Rezervare&);
	bool operator==(const Rezervare&);
	void setNr(char*);
	void setTip(char*);
	void setEliberata(bool);
	void setId(int);
	int getID();
	char* getNr();
	char* getTip();
	bool getElib();
	friend ostream& operator<<(ostream&, Rezervare&);
	friend istream& operator>>(istream&, Rezervare&);
	bool operator<(const Rezervare&);
	~Rezervare();
};



