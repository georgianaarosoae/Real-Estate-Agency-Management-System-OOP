#include "ItemMeniu.h"
#include<iostream>
ItemMeniu::ItemMeniu(string denumire) {
	this->denumire = denumire;
	activ = false;
	consola= GetStdHandle(STD_OUTPUT_HANDLE);
 }

ostream& operator<<(ostream& out, ItemMeniu it)
{
	int max = 100;
	out << "*";
	if (it.activ == 1) {
		SetConsoleTextAttribute(it.consola, 233);
	}
	for(int i=0; i<(max-it.denumire.length())/2;i++) out << " ";
	out << it.denumire;
	for (int i = 0; i < (max - it.denumire.length()) / 2; i++) out << " ";
	SetConsoleTextAttribute(it.consola, 7);
	out << "*";
	out << endl;
	return out;
}
