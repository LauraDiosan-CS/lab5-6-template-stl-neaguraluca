#pragma once

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
	void setNr(char*);
	void setTip(char*);
	void setEliberata(bool);
	void setId(int);
	~Rezervare();
};



