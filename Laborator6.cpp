#include <iostream>
//#include "Test.h"
#include "UI.h"
#include "Test.h"
#include "Entitate.h"
#include "ServiceR.h"
#include "RepoFile.h"
#include "RepoTemplate.h"


int main()
{
	testare();

	Repo<Rezervare>* repo = new RepoFile<Rezervare>("Rezervari.txt");
	((RepoFile<Rezervare>*)repo)->loadFromFile();
	ServiceR s(repo);
	UI u(s);
	u.showMenu();
	return 0;
}