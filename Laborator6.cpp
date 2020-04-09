#include <iostream>
//#include "Test.h"
#include "UI.h"
#include "Test.h"
#include "Entitate.h"
#include "ServiceR.h"
#include "RepoTemplate.h"


int main()
{
	
	RepoTemplate<Rezervare> r;
	ServiceR s(r);
	UI u(s);
	u.showMenu();
	return 0;
}

