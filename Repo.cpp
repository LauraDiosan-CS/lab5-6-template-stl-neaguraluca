#include"Repo.h"

Repo::Repo()
//constructor
{
	this->elem;
}

Repo::Repo(const Repo& r)
{
	this->elem = r.elem;
}

void Repo::addElem(Rezervare rez)
/*adauga un element
input: rez: Rezervare, rezervarea de adaugat*/
{
	elem.push_back(rez);
}

vector<Rezervare> Repo::getAll()
/*gaseste toate elementele salvate
output: elem: vector de Rezervare, elementele salvate*/
{
	return elem;
}

Repo::~Repo()
{}