#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Exceptie.h"
#include <map>
#include <algorithm>
#include <vector>
class Imobil
{
private:
	const int id;
	double suprafata;
	int nrCamere;
	map<string, int> camere;
	bool utilat;
	string adresa;
	char* zona;
	vector<string> dotari;
	static int numarImobile;

public:

	Imobil();
	Imobil(double suprafata, int nrCamere, bool utilat, string adresa, const char* zona, vector<string> dotari);
	Imobil(const Imobil& i);
	Imobil operator=(const Imobil& i);
	~Imobil();

	void setSuprafata(double suprafataNoua);
	double getSuprafata();

	void setNrCamere(int nrCamereNou);
	int getNrCamere();

	void setCamare(std::map<string, int> camereNou);
	std::map<string, int> getCamere();

	void setUtilat(bool utilatNou);
	bool getUtilat();

	void setAdresa(string adresaNoua);
	string getAdresa();

	void setZona(const char* zonaNoua);
	char* getZona();

	void setDotari(vector<string> dotariNou);
	vector<string> getDotari();

	bool operator==(const Imobil& i);

	friend istream& operator>>(istream& in, Imobil& i);
	friend ostream& operator<<(ostream& out, const Imobil i);
	friend ifstream& operator>>(ifstream& ifs, Imobil& i);
	friend ofstream& operator<<(ofstream& ofs, const Imobil i);
};
// int Imobil::numarTotal = 10;
