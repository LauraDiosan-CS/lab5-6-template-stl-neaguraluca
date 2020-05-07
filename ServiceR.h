#pragma once
#include "Entitate.h"
#include "RepoTemplate.h"
#include "RepoFile.h"
#include <vector>
using namespace std;

class ServiceR
{
private:
	//RepoTemplate<Rezervare> &repo;
	RepoFile<Rezervare> repo;
public:
	ServiceR();
	ServiceR(RepoFile<Rezervare>);

	//void setRepo(const RepoTemplate<Rezervare>&);
	void add(int, char*, char*, bool);
	void remove(int);
	void update(int, char*, char*, bool);
	Rezervare getById(int);
	vector<Rezervare> getAll();
	int calcProcent(char*);
	vector<char*> getAllTypes();
	void getPercentageByType();
	~ServiceR();
};
