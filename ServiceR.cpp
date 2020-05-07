#include "ServiceR.h"
#include <algorithm>
#include <set>
using namespace std;

ServiceR::ServiceR()
//construcctor implicit
{

}

ServiceR::ServiceR(RepoFile<Rezervare> repo)
//constructor general
{
	this->repo=repo;
}



void ServiceR::add(int id, char* nr, char* tip, bool eliberata)
/*apeleaza repo in vederea adaugarii unui element
input: id: int
	nr: string
	tip: string
	elib:bool*/
{
	Rezervare rez(id, nr, tip, eliberata);
	repo.add(rez);
	repo.saveToFile();
}


void ServiceR::remove(int id)
//apeleaza repo in vederea stergerii unui element
//input: id:int, id-ul elementului care va fi sters
{
	//Rezervare rez = repo.getById(id);
	repo.remove(id);
	repo.saveToFile();
}


void ServiceR::update(int id, char* nrNou, char* tipNou, bool eliberataNou)
/*apeleaza repo in vederea modificarii unui element
input: id: int, id-ul elementului care va fi modificat
	nrNou: string, noul numar al camerei
	tipNou: string, noul tip
	elibNou:bool, noua stare a eliberarii*/
{
	//Rezervare rez_vechi = repo.getById(id);
	//Rezervare rez_nou(id, nrNou, tipNou, eliberataNou);
	Rezervare old = repo.getById(id);
	Rezervare nou(id, nrNou, tipNou, eliberataNou);
	repo.update(old, nou);
	repo.saveToFile();
}


vector<Rezervare> ServiceR::getAll()
{
	vector<Rezervare> vect = repo.getAll();
	vector<Rezervare> vectServ(vect.begin(), vect.end());
	return vectServ;
}

Rezervare ServiceR::getById(int id)
{
	Rezervare found = repo.getById(id);
	return found;
}

vector<char*> ServiceR::getAllTypes()
//creaza o lista cu toate tipurile de camera existente
{
	vector<char*> tipuri;
	
	vector<char*> unice;
	vector<Rezervare> rezervari = getAll();
	int tot_tipuri = -1;
	for (Rezervare r : rezervari)
	{
		tipuri.push_back(r.getTip());
		tot_tipuri++;
	}
	for (int i = 0; i < tot_tipuri-1; i++)
	{
		bool sem = true;
		for (int j =i+1 ; j < tot_tipuri; j++)
			if (strcmp(tipuri[i], tipuri[j])==0)
				sem = false;
		if (sem)
			unice.push_back(tipuri[i]);
	}

	bool sem = true;
	for (int j =0; j < tot_tipuri; j++)
		if (tipuri[tot_tipuri-1] == tipuri[j])
			sem = false;
	if (sem)
		unice.push_back(tipuri[tot_tipuri]);

	return unice;
}

int ServiceR::calcProcent(char* tip)
{
	int tot = 0;
	int procent = 0;
	vector<Rezervare> r = getAll();
	for (int i=0; i<r.size(); i++)
	{

		if (strcmp(r[i].getTip(), tip)==0)
		{
			tot++;
			if (r[i].getElib() == true)
				procent++;
		};
		//return tot;
		int rezultat;
		if (tot == 0) rezultat = 0;
		else
			rezultat = (procent * 100) / tot;
		return rezultat;
	}
}

void ServiceR::getPercentageByType()
//calculeaza procentul ocuparii fiecarui tip
{
	vector<Rezervare> r = getAll();
	vector<char*> unice = getAllTypes();
	//for (int i = 0; i < unice.size(); i++)
	//	calcProcent(unice[i]);
	char aux[10];
	for (int i=0; i<unice.size()-1; i++)
		for (int j=i+1;j<unice.size();j++)
			if (calcProcent(unice[i]) > calcProcent(unice[j]))
			{
				strcpy_s(aux, strlen(unice[i]) + 1, unice[i]);
				strcpy_s(unice[i], strlen(unice[j]) + 1, unice[j]);
				strcpy_s(unice[j], strlen(aux) + 1, aux);
			}
	for(int i=0; i<unice.size(); i++)
		cout << unice[i] << ": " << calcProcent(unice[i]) << "%;" << endl;
	
}



ServiceR::~ServiceR()
//destructor
{}