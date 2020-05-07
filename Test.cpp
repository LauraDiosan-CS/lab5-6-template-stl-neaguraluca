#include"Test.h"
#include "RepoFile.h"
#include "RepoTemplate.h"
#include "ServiceR.h"
#include <assert.h>
#include <cassert>

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

	assert(r2.getElib() == false);
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

	char tip1[10];
	strcpy_s(tip1, strlen("chy") + 1, "chy");
	assert(serv.calcProcent(tip1)==0);

	char tip2[10];
	strcpy_s(tip2, strlen("abc") + 1, "abc");
	assert(serv.calcProcent(tip1) == 50);
		
};

void test3()
//testeaza repo file
{
	RepoFile<Rezervare> rf("Rezervari.txt");
	rf.loadFromFile();
	vector<Rezervare> all = rf.getAll();

	assert(all.size() == 4);

	Rezervare rez1(5, "22", "single", false);
	Rezervare rez2(7, "12", "double", false);

	rf.add(rez1);
	rf.saveToFile;
	assert(all.size() == 5);

	rf.remove(5);
	rf.saveToFile();
	assert(all.size() == 4);

	rf.add(rez2);
	rf.saveToFile;
	assert(all.size() == 5);

}

void testare()
{
	test1();
	test2();
	test3();
	cout << "Teste trecute"<<endl;
}