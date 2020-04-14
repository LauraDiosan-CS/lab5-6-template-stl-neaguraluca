#pragma once
#include "Entitate.h";
#include "RepoTemplate.h"
#include <vector>
using namespace std;

class RepoFile :
	public RepoTemplate<Rezervare>
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* );
	void add(Rezervare);
	void remove(Rezervare);
	void update(int, char*, char*, bool);
	void loadFromFile(const char* );
	void saveToFile();
	~RepoFile();
};