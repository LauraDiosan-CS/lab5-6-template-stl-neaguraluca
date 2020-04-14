#include "ServiceR.h"
#include <algorithm>
using namespace std;

ServiceR::ServiceR()
//construcctor implicit
{

}

ServiceR::ServiceR(const RepoTemplate<Rezervare>& r)
//constructor general
{
	repo = r;
}


void ServiceR::setRepo(const RepoTemplate<Rezervare>& r)
{
	repo = r;
}


void ServiceR::add(int id, const char* nr, const char* tip, bool eliberata)
/*apeleaza repo in vederea adaugarii unui element
input: id: int
	nr: string
	tip: string
	elib:bool*/
{
	Rezervare rez(id, nr, tip, eliberata);
	repo.add(rez);
}


void ServiceR::remove(int id)
//apeleaza repo in vederea stergerii unui element
//input: id:int, id-ul elementului care va fi sters
{
	//Rezervare rez = repo.getById(id);
	repo.remove(id);
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
	repo.update(id, nrNou, tipNou, eliberataNou);
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
	vector<Rezervare> rezervari = getAll();
	for (Rezervare r : rezervari)
		//if (!find(tipuri.begin(), tipuri.end(), r.getTip))
		tipuri.push_back(r.getTip());
	return tipuri;
}

vector<double> ServiceR::getPercentageByType()
//calculeaza procentul ocuparii fiecarei camere
{
	vector<char*> tipuri = getAllTypes();
	vector<int> tot;     //numarul total de camere pt fiecare tip
	vector<int> procent;	//numarul de camere ocupate pt fiecare tip
	vector<double> rezultat;	//procentul reprezentat de camerele ocupate fata de totalul de camere pt fiecare tip
	int i = 0;
	//char tip[10];
	for (char* tip : tipuri)
		for (Rezervare r : getAll())
		{

			if (r.getTip() == tip)
			{
				tot[i] ++;
				if (r.getElib() == 0)
					procent[i]++;
			};
			rezultat[i] = ( procent[i] / tot[i]) * 100;
			i++;
		}
	sort(rezultat.begin(), rezultat.end());
	return rezultat;
}

ServiceR::~ServiceR()
//destructor
{}