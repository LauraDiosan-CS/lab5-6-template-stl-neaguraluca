#pragma once
#include "Entitate.h"
#include "RepoTemplate.h"
#include <vector>
using namespace std;

class ServiceR
{
private:
	RepoTemplate<Rezervare> repo;
public:
	ServiceR();
	ServiceR(const RepoTemplate<Rezervare>&);
	void setRepo(const RepoTemplate<Rezervare>&);
	void add(int, const char*, const char*, bool);
	void remove(int);
	void update(int, char*, char*, bool);
	Rezervare getById(int);
	vector<Rezervare> getAll();
	vector<char*> getAllTypes();
	vector<double> getPercentageByType();
	~ServiceR();
};
