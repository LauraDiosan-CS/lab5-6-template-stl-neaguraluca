#include"Test.h"
#include <assert.h>

void testare()
{
	Repo rep;
	Rezervare r1 = Rezervare(1, "10", "abc", true);
	Rezervare r2 = Rezervare(2, "14", "abc", false);
	Rezervare r3 = Rezervare(3, "27", "djd", true);
	rep.addElem(r1);
	rep.addElem(r2);
	rep.addElem(r3);
	vector<Rezervare> rez = rep.getAll();
	assert(rez.size == 2);

}