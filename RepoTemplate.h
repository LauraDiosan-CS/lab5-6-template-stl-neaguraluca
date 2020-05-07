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
	void update(const T&, const T&);
	vector<T> getAll();
	Rezervare getById(int);
	int getSize();
	T getElement(int poz)
	{
		return this->elem[poz];
	}
	~RepoTemplate();
};
template <class T>
inline void RepoTemplate<T>::add(const T& e)
/*adauga un element
input: e:elementul de adaugat*/
{
	elem.push_back(e);
}

template <class T>
inline void RepoTemplate<T>::remove(int id)
/*sterge un element
input: e:elementul de sters*/
{
	Rezervare rez = getById(id);
	vector<Rezervare>::iterator it;
	it = find(elem.begin(), elem.end(), rez);
	if (it != elem.end()) elem.erase(it);

}

template <class T>
inline void RepoTemplate<T>::update(const T& rez, const T& rez_nou)
/*modifica un element
input: id, int: id-ul elementului de modificat
		*nou: parametrii elementului cu care se modifica*/
{
	
	replace(elem.begin(), elem.end(), rez, rez_nou);
	
}

template <class T>
inline Rezervare RepoTemplate<T>::getById(int id)
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
inline vector<T> RepoTemplate<T>::getAll()
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



