#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include "Imobil.h";
#include "Locatie.h"

class ImobilVandutInchiriat : public Imobil
{
private:
	string tip;
	int numar;
	char* data; // data la care a fost vandut sau inchiriat
	// if pret???
	Locatie* loc;

public:
	ImobilVandutInchiriat();
	ImobilVandutInchiriat(double pret, int comision, bool disponibil, Locatie* locatie, string tip, int numar, const char* data);
	ImobilVandutInchiriat(const ImobilVandutInchiriat& vi);
	~ImobilVandutInchiriat();

	ImobilVandutInchiriat operator=(const ImobilVandutInchiriat& vi);
	void setNumarDisponibile(int numarNou);
	int getNumarDisponibile();

	friend istream& operator>>(istream& in, ImobilVandutInchiriat& vi);
	friend ostream& operator<<(ostream& out, ImobilVandutInchiriat vi);
	friend ifstream& operator>>(ifstream& ifs, ImobilVandutInchiriat& vi);
	friend ofstream& operator<<(ofstream& ofs, ImobilVandutInchiriat vi);
};
