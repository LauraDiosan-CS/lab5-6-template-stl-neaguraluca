#pragma once
#include "Entitate.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


template <class T>class RepoTemplate
{
protected:
	vector<T> elem;
public:
	RepoTemplate<T>(){}
	void add(const T&);
	void remove(int);
	void update(int, char*, char*, bool);
	vector<T> getAll();
	Rezervare getById(int);
	int getSize();
	~RepoTemplate();
};
template <class T>
void RepoTemplate<T>::add(const T& e)
/*adauga un element
input: e:elementul de adaugat*/
{
	elem.push_back(e);
}

template <class T>
void RepoTemplate<T>::remove(int id)
/*sterge un element
input: e:elementul de sters*/
{
	Rezervare rez = getById(id);
	vector<Rezervare>::iterator it;
	it = find(elem.begin(), elem.end(), rez);
	if (it != elem.end()) elem.erase(it);

}

template <class T>
void RepoTemplate<T>::update(int id, char* nrNou, char* tipNou, bool eliberataNou)
/*modifica un element
input: vechi: elementul de modificat
		nou: elementul cu care se modifica*/
{
	Rezervare rez = getById(id);
	Rezervare rez_nou(id, nrNou, tipNou, eliberataNou);
	replace(elem.begin(), elem.end(), rez, rez_nou);
	

}

template <class T>
Rezervare RepoTemplate<T>::getById(int id)
/*gaseste rezervarea aferenta unui id
input: id
output: rezervarea a carei id este cel cautat*/
{
	vector<Rezervare> all = getAll();
	for (Rezervare r : all)
		if (r.getID() == id)
			return r;
}

template<class T>
vector<T> RepoTemplate<T>::getAll()
{
	return elem;
}


template <class T>
int RepoTemplate<T>::getSize()
{
	return elem.size();
}

template <class T> RepoTemplate<T>::~RepoTemplate()
{}



