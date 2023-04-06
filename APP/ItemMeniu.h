#pragma once
#include <string>
#include <windows.h>;
#include<iostream>

using namespace std;
class ItemMeniu
{
private:
	string denumire;
	HANDLE consola;
public:
	ItemMeniu(string denumire);
	friend ostream& operator<<(ostream& out, ItemMeniu it);
	bool activ;
};

