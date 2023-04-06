#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Exceptie.h"

class Locatie
{
private:
	int idLocatie;
	string denumireLocatie;
	int nrImobileDisponibilePerLocatie;
	int nrImobileVandutePerLocatie;
	int nrImobileInchiriatePerLocatie;
	static int TotalLocatii;

public:
	// static int TotalLocatii;
	Locatie();
	Locatie (string denumireLocatieint,int nrImobileDisponibilePerLocatie,int nrImobileVandutePerLocatie, int nrImobileInchiriatePerLocatie);
	Locatie(const Locatie& loc);
	Locatie operator=(const Locatie& loc);

	// setteri si getteri:
	string getDenumireLocatie();
	void setDebumireLocatie(string denumireNoua);
	int getNrImobileDisponibilePerLocatie();
	void setNrImobileDisponibilePerLocatie(int nrImobileDisponibilePerLocatie);
	int getNrImobileVandutePerLocatie();
	void setNrImobileVandutePerLocatie(int nrImobileVandutePerLocatie);
	int getNrImobileInchiriatePerLocatie();
	void setNrImobileInchiriatePerLocatie(int nrImobileInchiriatePerLocatie);
	//

	void vanzareImobil();
	void inchiriereImobil();
	void imobilNouDisponibil();
	void imobilIndisponibil();
	Locatie operator++();
	Locatie operator+=(int valoare);
	bool operator<(Locatie loc);
	bool operator!();
	~Locatie();
	friend ostream& operator<<(ostream& out, Locatie& loc);
	friend istream& operator>>(istream& in, Locatie& loc);
	friend ofstream& operator<<(ofstream& ofs, Locatie& loc);
	friend ifstream& operator>>(ifstream& ifs, Locatie& loc);
	void scrieInFisierBinar(fstream& fisier);
	void citesteDinFisierBinar(fstream& fisier);
};
