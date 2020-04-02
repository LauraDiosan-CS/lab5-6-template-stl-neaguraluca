
#pragma once
#include "Entitate.h"
#include <iostream>
#include <vector>
using std::vector;


class Repo
{
private:
	vector<Rezervare> elem;
public:
	Repo();
	Repo(const Repo&);
	void addElem(Rezervare);
	vector<Rezervare>getAll();
	~Repo();
};
