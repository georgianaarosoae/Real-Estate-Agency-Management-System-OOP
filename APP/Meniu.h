#pragma once
#include "ItemMeniu.h"
#include <list>
#include<conio.h>
class Meniu
{
private:
	list<string>lista;
	int optiuneActiva;
public:
	Meniu();
	void Adauga(string nume);
	int Citeste();
	friend ostream& operator<<(ostream& out, Meniu m);

};



