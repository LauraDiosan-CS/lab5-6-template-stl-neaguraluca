#pragma once
#include"RepoTemplate.h"
#include <fstream>
#include <iostream>
#include <cstddef>



template <class T> class RepoFile : public RepoTemplate<T>
{

public:
	RepoFile();
	RepoFile(const char* );
	void loadFromFile();
	void saveToFile();
	~RepoFile();
};


template<class T>
inline RepoFile<T>::RepoFile()
//constructor implicit
{}


template<class T>
inline RepoFile<T>::RepoFile(const char* fName)
//constructor cu parametrii
//input: fname: char*, numele fisierului care va fi folosit
{
}


template<class T>
inline void RepoFile<T>::loadFromFile()
//incarca datele din fisier
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line))
	{
		T ob(line, ' ');
		RepoTemplate<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepoFile<T>::saveToFile()
//salveaza datele in fisier
{
	ofstream f(RepoFile<T>::fileName);
	for (T crt : Repository<T>::elem)
	{
		f << T.getId+" "+T.getNr+" "+T.getTip+" "+T.getElib << endl;
	}
}


template<class T>
inline RepoFile<T>::~RepoFile()
{}


