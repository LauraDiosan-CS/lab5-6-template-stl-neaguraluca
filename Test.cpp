#include"Test.h"
#include "ServiceR.h"
#include <assert.h>

void test1()
//testeaza CRUD-uri
{
	RepoTemplate<Rezervare> rep;
	Rezervare r1 = Rezervare(1, "10", "abc", true);
	Rezervare r2 = Rezervare(2, "14", "abc", false);
	Rezervare r3 = Rezervare(3, "27", "djd", true);

	rep.add(r1);
	rep.add(r2);
	rep.add(r3);

	vector<Rezervare> rez = rep.getAll();

	assert(rez.size() == 3);    
	rep.remove(3);

	assert(rep.getById(1) == r1);

	assert(rez.size() == 2);
}

void test2()
//testeaza functionalitatea
{
	ServiceR serv;
	RepoTemplate<Rezervare> rep;

	Rezervare r3 = Rezervare(3, "27", "djd", true);
	Rezervare r1 = Rezervare(1, "10", "abc", true);
	Rezervare r2 = Rezervare(2, "14", "abc", false);
	Rezervare r4 = Rezervare(1, "10", "abc", true);
	Rezervare r5 = Rezervare(2, "14", "abc", false);
	Rezervare r6 = Rezervare(3, "27", "chy", false);

	rep.add(r3);
	rep.add(r1);
	rep.add(r2);
	rep.add(r4);
	rep.add(r5);
	rep.add(r6);

	assert(serv.getAllTypes().size() == 3);
	assert(serv.getPercentageByType()[0] == 100);
	assert(serv.getPercentageByType()[1] == 50);
	assert(serv.getPercentageByType()[2] == 0);
};

void testare()
{
	test1();
	//test2();
}