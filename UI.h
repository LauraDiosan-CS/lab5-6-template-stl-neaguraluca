#pragma once
#include "ServiceR.h"
#include "Test.h"

class UI
{
private:
	ServiceR serv;
	void addUI();
	void removeUI();
	void updateUI();
	void showAllUI();
	void runTests();
	void procentajUI();
	void populate();
	//void showTypes();
public:
	UI();
	UI(ServiceR&);
	void showMenu();
	~UI();
};